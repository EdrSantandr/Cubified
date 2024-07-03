// EdrSantandr Dev

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CubiCharacterBase.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UBoxComponent;

UCLASS(Abstract)
class CUBIFIED_API ACubiCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	
	ACubiCharacterBase();
	
	UFUNCTION()
	void MovementAxis(const FVector& Direction, const float& Flag);

	UPROPERTY(EditDefaultsOnly, Category="CharacterMovement")
	float MovementStep = 1000.f;

	UPROPERTY(EditDefaultsOnly, Category="CharacterMovement")
	float RotationTime = 1.f;

	UPROPERTY(EditAnywhere, Category="CameraConfig")
	float CameraArmLength = 1200.f;

	UPROPERTY(EditDefaultsOnly, Category="CameraConfig")
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(EditDefaultsOnly, Category="CameraConfig")
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	FTimerHandle TimerHandle_MovementDelay;
	FTimerDelegate Delegate;

	bool bActorMovement = false;

	float TotalTime = 0.f;
	float NinetyDegrees = 90.f;
	FTransform OriginalCameraTransform = FTransform();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category="Mesh")
	TObjectPtr<UBoxComponent> BoxComponent;

	UFUNCTION()
	void MovementDelay_Elapsed(const FVector& Position);
};