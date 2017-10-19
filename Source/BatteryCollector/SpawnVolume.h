// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
 
    //Returns the spawning of the pickups
    FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }
    
    //Returns the random position within the world for the pickups to be placed
    UFUNCTION(BlueprintPure, Category = "Spawning")
    FVector GetRandomPointsInVolume();
    
protected:
    // Stores the pickup object
    UPROPERTY(EditAnywhere, Category = "Spawning")
    TSubclassOf<class APickup> WhatToSpawn;
    
    //Timer for the spawning of the Pickups
    FTimerHandle SpawnTimer;
    
    //Setting the Delay range for the Pickup
    UPROPERTY(EditAnywhere, Category = "Spawning")
    float SpawnDelayRangeLow;
    
    UPROPERTY(EditAnywhere, Category = "Spawning")
    float SpawnDelayRangeHigh;

private:
    //Allows the spawning of the pickups
   UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
    class UBoxComponent* WhereToSpawn;
    
    //Spawns the pickup in the world
    void SpawnPickup();
    
    //Delay time for the Pickup
    float SpawnDelay;
	
};
