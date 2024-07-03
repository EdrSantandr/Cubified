// EdrSantandr Dev


#include "Player/CubiPlayerController.h"

#include <string>

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Character/CubiCharacterBase.h"

ACubiPlayerController::ACubiPlayerController()
{
	bReplicates = true;
}

void ACubiPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(CubiContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(CubiContext, 0);
	bShowMouseCursor = false;
	FInputModeGameAndUI InputModeGameAndUI;
	InputModeGameAndUI.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeGameAndUI.SetHideCursorDuringCapture(true);
	SetInputMode(InputModeGameAndUI);
}

void ACubiPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Started, this, &ACubiPlayerController::Move);
}

void ACubiPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2d>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation (0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (ACubiCharacterBase* CubiCharacter = Cast<ACubiCharacterBase>(GetPawn<APawn>()))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Move forward vector [%s] and inputaxisvector: [%f]"),*ForwardDirection.ToString(), InputAxisVector.Y);
		const FVector VectorXAxis = ForwardDirection*InputAxisVector.Y;
		const float VectorXLenght = VectorXAxis.Length();

		const FVector VectorYAxis = RightDirection*InputAxisVector.X;
		const float VectorYLenght = VectorYAxis.Length();

		if (VectorXLenght > 0)
		{
			CubiCharacter->MovementAxis(ForwardDirection, InputAxisVector.Y);
		}
		if (VectorYLenght > 0)
		{
			CubiCharacter->MovementAxis(RightDirection, InputAxisVector.X);
		}
	}
}

