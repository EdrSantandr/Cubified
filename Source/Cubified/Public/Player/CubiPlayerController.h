// EdrSantandr Dev

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CubiPlayerController.generated.h"

class UInputMappingContext;
/**
 * 
 */
UCLASS()
class CUBIFIED_API ACubiPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ACubiPlayerController();
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> CubiContext;
	
};
