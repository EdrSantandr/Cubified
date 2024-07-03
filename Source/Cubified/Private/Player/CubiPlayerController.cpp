// EdrSantandr Dev


#include "Player/CubiPlayerController.h"

#include <string>

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

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

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &ACubiPlayerController::Move);
}

void ACubiPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2d>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation (0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		//ControlledPawn->AddMovementInput(ForwardDirection, Inpstd::to_string(ustd::to_string(tAxisVector.Y);
		UE_LOG(LogTemp, Warning, TEXT("Move forward vector [%s] and inputaxisvector: [%f]"),*ForwardDirection.ToString(), InputAxisVector.Y);
		//ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
		UE_LOG(LogTemp, Warning, TEXT("Move right vector [%s] and inputaxisvector: [%f]"),*RightDirection.ToString(), InputAxisVector.X);
	}
}
