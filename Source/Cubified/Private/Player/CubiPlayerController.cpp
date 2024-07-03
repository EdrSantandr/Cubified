// EdrSantandr Dev


#include "Player/CubiPlayerController.h"
#include "EnhancedInputSubsystems.h"

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
