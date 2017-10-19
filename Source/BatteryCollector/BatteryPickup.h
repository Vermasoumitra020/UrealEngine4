// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYCOLLECTOR_API ABatteryPickup : public APickup
{
	GENERATED_BODY()
	
public:
    // Sets default values for this actor's properties
    ABatteryPickup();
	
    //Overriding the pickup collection function
    void WasCollected_Implementation() override ;
    
    //returns the power level of the battery
    float GetPower();
    
protected:
    //Sets the battery power level
    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
    float BatteryPower;
    
};
