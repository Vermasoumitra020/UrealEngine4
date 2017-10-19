// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "BatteryCollectorGameMode.h"
#include "BatteryCollectorCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

ABatteryCollectorGameMode::ABatteryCollectorGameMode()
{
    PrimaryActorTick.bCanEverTick = true;
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
    
    //Default DecayRate of the character
    DecayRate = 0.01f;
}
void ABatteryCollectorGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    ABatteryCollectorCharacter* const MyCharacter = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
    
    if(MyCharacter)
    {
        if(MyCharacter->GetCurrentPower() > 0)
        {
            MyCharacter->UpdatePower(-DeltaTime * DecayRate * (MyCharacter->GetInitialPower()));
            
             UE_LOG(LogClass, Log, TEXT("%f, %f"), MyCharacter->GetInitialPower(), MyCharacter->GetCurrentPower())
        }
    }
}
