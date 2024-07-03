// EdrSantandr Dev


#include "Character/CubiCharacterBase.h"

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ACubiCharacterBase::ACubiCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
	BoxComponent = CreateDefaultSubobject<UBoxComponent>("Box");
	BoxComponent->SetupAttachment(GetRootComponent());

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->SetWorldRotation(FRotator(-45.f, 0.f, 0.f));
	SpringArmComponent->TargetArmLength = CameraArmLength;
	SpringArmComponent->bEnableCameraLag = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->bUsePawnControlRotation = false;
}

void ACubiCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	

	//GetWorld()->GetTimerManager().ClearTimer(TimerHandle_MovementDelay);
	//GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

void ACubiCharacterBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (bActorMovement)
	{
		TotalTime += DeltaSeconds;
		UE_LOG(LogTemp,Warning, TEXT("total time: [%f]"), TotalTime);
		const FRotator DeltaRotation = FRotator(-(NinetyDegrees) * (TotalTime/RotationTime), 0.f, 0.f);
		UE_LOG(LogTemp,Warning, TEXT("Total Rotation: [%s]"), *DeltaRotation.ToString());
		const FRotator NegateDeltaRotation = FRotator((NinetyDegrees) * (TotalTime/RotationTime), 0.f, 0.f);
		SetActorRotation(DeltaRotation);
	}
}

void ACubiCharacterBase::MovementDelay_Elapsed(const FVector& Position)
{
	UE_LOG(LogTemp,Warning, TEXT("MovementDelay Elapsed after [%f] seconds"),RotationTime);
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle_MovementDelay);
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	bActorMovement = false;
	SetActorLocation(Position);
	SetActorRotation(FRotator(-90.f, 0.f, 0.f));
	CameraComponent->SetWorldTransform(OriginalCameraTransform);
	CameraComponent->bUsePawnControlRotation = false;
}

void ACubiCharacterBase::MovementAxis(const FVector& Direction, const float& Flag)
{
	const FVector VectorAxis = Direction * Flag * MovementStep;
	FVector OriginalPosition = GetActorLocation();
	FVector Position = GetActorLocation();
	Position += VectorAxis;
	UE_LOG(LogTemp, Warning, TEXT("Newposition [%s]"), *Position.ToString());
	OriginalCameraTransform = CameraComponent->GetComponentTransform();
	CameraComponent->bUsePawnControlRotation = true;

	Delegate.BindUFunction(this, "MovementDelay_Elapsed", Position);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_MovementDelay, Delegate, RotationTime, false);

	bActorMovement = true;
}

