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

	UPROPERTY(EditAnywhere, Category="CharacterMovement")
	float CameraArmLength = 1200.f;

	UPROPERTY(EditDefaultsOnly, Category="CharacterMovement")
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(EditDefaultsOnly, Category="CharacterMovement")
	TObjectPtr<USpringArmComponent> SpringArmComponent;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Mesh")
	TObjectPtr<UBoxComponent> BoxComponent;
};