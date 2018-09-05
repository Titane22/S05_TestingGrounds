// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

class UActorPool;

UCLASS()
class S05_TESTINGGROUNDS_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable,Category="Pool")
	void SetPool(UActorPool* InPool);

	void PositionNavMeshBoundsVolume();

	// MinSpawn to MaxSpawn Spawns ToSpawn actors,set actors in blueprint 
	UFUNCTION(BlueprintCallable, Category = Spawn)
	void PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn, int MaxSpawn, int Radius, float MinScale = 1.f, float MaxScale = 1.f);

	UPROPERTY(EditDefaultsOnly, Category = "Navgation")
	FVector NavMeshBoundsVolumeOffset;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	FVector MinExtent;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	FVector MaxExtent;

private:
	// set randomise rotation and scale,and find the spawn point
	void PlaceActor(TSubclassOf<AActor> ToSpawn, FVector SpawnPoint, int Rotation, float Scale);

	// Find where to create MAX_ATTEMPS times.
	bool FindEmptyLocation(OUT FVector& OutLocation, float Radius);

	// if it is true, can spawn actors
	bool CanSpawnAtLocation(FVector Location, float Radius);

	UActorPool* Pool;

	AActor* NavMeshBoundsVolume;
};
