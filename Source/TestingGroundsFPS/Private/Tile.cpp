// Fill out your copyright notice in the Description page of Project Settings.

#include "Tile.h"


// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATile::PlaceActor()
{
	FVector Min(0,-2000,0);
	FVector Max(4000, 2000, 0);
	FBox Bounds(Min, Max);
	
	for (int i = 0; i < 20; i++)
	{
		FVector SpawnPont = FMath::RandPointInBox(Bounds);
	}
}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

