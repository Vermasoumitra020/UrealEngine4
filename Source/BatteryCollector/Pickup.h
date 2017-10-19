// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
    //Returns the pickup object
    FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }
    
    //Getting the state whether or not the pickup is active
    UFUNCTION(BlueprintPure, Category = "Pickup")
    bool IsActive();
    
    //Setting the current active state of the pickup
    UFUNCTION(BlueprintCallable, Category = "Pickup")
    void SetActive(bool CurrentActiveState);
    
    //Called when the pickup is collected
    UFUNCTION(BlueprintNativeEvent)
    void WasCollected();
    virtual void WasCollected_Implementation();
    
protected:
    //Active state of the battery
    bool bIsActive;
	
private:
    //Creating a pickup object
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
    class UStaticMeshComponent* PickupMesh;
	
};
