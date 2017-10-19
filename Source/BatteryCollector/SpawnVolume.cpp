// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnVolume.h"
#include "Kismet/KismetMathLibrary.h"
#include "Pickup.h"


// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;
    
    //Creating the sub object of the area for spawning
    WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawning"));
    RootComponent = WhereToSpawn;
    
    //Setting the  spawn delay range for the timer
    SpawnDelayRangeLow = 1.0f;
    SpawnDelayRangeHigh = 4.5f;

}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
    
    //Sets the delay timer for the spawning of the pickup objects in the world
    SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
    GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Returns the Random points or co ordinates within the bounoding box
FVector ASpawnVolume::GetRandomPointsInVolume()
{
    FVector SpawnOrigin = WhereToSpawn->Bounds.Origin;
    FVector SpawnExtent = WhereToSpawn->Bounds.BoxExtent;
    
    return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnExtent);
}

void ASpawnVolume::SpawnPickup()
{
    if(WhatToSpawn != NULL)
    {
        UWorld* const World = GetWorld();
        if(World)
        {
            //Setting the spawning parameters
            FActorSpawnParameters SpawnParams;
            SpawnParams.Owner = this;
            SpawnParams.Instigator = Instigator;
            
            //Setting the Random location for the pickup to spawn
            FVector RandomLocation = GetRandomPointsInVolume();
            
            //Sets the rotation for the pickup objects
            FRotator SpawnRotation;
            SpawnRotation.Yaw = FMath::FRand() * 360.0f;
            SpawnRotation.Pitch = FMath::FRand() * 360.0f;
            SpawnRotation.Roll = FMath::FRand() * 360.0f;
            
            //spawns the pickup objects in the valid world
             APickup* const SpawnedPickup = World->SpawnActor<APickup>(WhatToSpawn, RandomLocation, SpawnRotation, SpawnParams);
            
            //Sets the delay timer for the spawning of the pickups objects in the world
            SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
            GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawnVolume::SpawnPickup, SpawnDelay, false);
            
        }
    }
    
}










