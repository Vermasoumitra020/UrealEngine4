// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"


// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    
    //The current state of the pickupo is always active
    bIsActive = true;
    
    //Creating the subloject of the pickup mesh that we defined in our header file
    PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pickup"));
    RootComponent = PickupMesh;
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Returns the active state of the battery
bool APickup::IsActive()
{
    return bIsActive;
}

//Sets the current active state of the battery
void APickup::SetActive(bool CurrentActiveState)
{
    bIsActive = CurrentActiveState;
}

void APickup::WasCollected_Implementation()
{
    //Defining a message for the debug
    FString PickupDebugString = GetName();
    UE_LOG(LogClass, Log, TEXT("You have collected %s"), *PickupDebugString);
}








