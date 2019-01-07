// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestingGroundsFPSGameMode.h"
#include "InfiniteTerrainGameMode.generated.h"

/**
 * 
 */
class ANavMeshBoundsVolume;

UCLASS()
class TESTINGGROUNDSFPS_API AInfiniteTerrainGameMode : public ATestingGroundsFPSGameMode
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "AIBoundVolume")
	void PopulateBoundVolumePool();


private:
	void AddToPool(ANavMeshBoundsVolume *VolumeToAdd);
	
	
	
};
