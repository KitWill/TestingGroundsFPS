// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestingGroundsFPSGameMode.h"
#include "InfiniteTerrainGameMode.generated.h"

/**
 * 
 */
class ANavMeshBoundsVolume;
class UActorPool;

UCLASS()
class TESTINGGROUNDSFPS_API AInfiniteTerrainGameMode : public ATestingGroundsFPSGameMode
{
	GENERATED_BODY()
public:
	AInfiniteTerrainGameMode();

	UFUNCTION(BlueprintCallable, Category = "AIBoundVolume")
	void PopulateBoundVolumePool();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pool")
	 UActorPool *NavMeshBoundsVolumePool;
private:
	void AddToPool(ANavMeshBoundsVolume *VolumeToAdd);
	
	
	
};
