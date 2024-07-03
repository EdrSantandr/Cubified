// EdrSantandr Dev


#include "Character/CubiCharacterBase.h"

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ACubiCharacterBase::ACubiCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
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
}

void ACubiCharacterBase::MovementAxis(const FVector& Direction, const float& Flag)
{
	const FVector VectorAxis = Direction * Flag * MovementStep;
	FVector Position = GetActorLocation();
	Position += VectorAxis;
	SetActorLocation(Position);
	UE_LOG(LogTemp, Warning, TEXT("Newposition [%s]"), *Position.ToString());
}

