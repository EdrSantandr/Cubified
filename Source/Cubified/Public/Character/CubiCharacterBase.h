// EdrSantandr Dev

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CubiCharacterBase.generated.h"

UCLASS(Abstract)
class CUBIFIED_API ACubiCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	
	ACubiCharacterBase();

protected:
	virtual void BeginPlay() override;


};
