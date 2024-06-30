// EdrSantandr Dev


#include "Character/CubiCharacterBase.h"

#include "Components/BoxComponent.h"

// Sets default values
ACubiCharacterBase::ACubiCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	BoxComponent = CreateDefaultSubobject<UBoxComponent>("Box");
	BoxComponent->SetupAttachment(GetRootComponent());
}

void ACubiCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}
