// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryPickup.h"

//Sets the default value
ABatteryPickup::ABatteryPickup()
{
    //Applying physics effect over the pickup
    APickup::GetMesh()->SetSimulatePhysics(true);
    
    //Setting the default battery power
    BatteryPower = 150.0f;
}

void ABatteryPickup::WasCollected_Implementation()
{
    //Calling the base class function
    Super::WasCollected_Implementation();
    
    //Destroying the battery after collected
    Destroy();
}

float ABatteryPickup::GetPower()
{
    return BatteryPower;
}
