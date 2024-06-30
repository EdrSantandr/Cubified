// EdrSantandr Dev

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CubiCharacterBase.generated.h"

class UBoxComponent;

UCLASS(Abstract)
class CUBIFIED_API ACubiCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	
	ACubiCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Mesh")
	TObjectPtr<UBoxComponent> BoxComponent;

};
