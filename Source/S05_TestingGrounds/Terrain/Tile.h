// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

USTRUCT()
struct FSpawnPosition
{
	GENERATED_USTRUCT_BODY()

	FVector SpawnPoint;
	int Rotation;
	float Scale;
};

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

	// MinSpawn to MaxSpawn Spawns ToSpawn actors,set actors in blueprint 
	UFUNCTION(BlueprintCallable, Category = Spawn)
	void PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn, int MaxSpawn, int Radius, float MinScale = 1.f, float MaxScale = 1.f);

	// MinSpawn to MaxSpawn Spawns ToSpawn actors,set actors in blueprint 
	UFUNCTION(BlueprintCallable, Category = Spawn)
		void PlaceAIPawns(TSubclassOf<APawn> ToSpawn, int MinSpawn, int MaxSpawn, int Radius);

	

	UPROPERTY(EditDefaultsOnly, Category = "Navgation")
	FVector NavMeshBoundsVolumeOffset;

	// min range of Ground
	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	FVector MinExtent;

	// max range of Ground
	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	FVector MaxExtent;

private:
	void PositionNavMeshBoundsVolume();

	// set randomise rotation, scale and find the spawn point
	void PlaceActor(TSubclassOf<AActor> ToSpawn,FSpawnPosition SpawnPosition);

	// set randomise rotation and find the spawn point
	void PlaceAIPawn(TSubclassOf<APawn> ToSpawn, FSpawnPosition SpawnPosition);

	// Get randomly spawn position between MinSpawn to MaxSpawn;
	TArray<FSpawnPosition> RandomSpawnPositions(int MinSpawn, int MaxSpawn, int Radius, float MinScale = 1.f, float MaxScale = 1.f);

	// Find where to create MAX_ATTEMPS times.
	bool FindEmptyLocation(OUT FVector& OutLocation, float Radius);

	// if it is true, can spawn actors
	bool CanSpawnAtLocation(FVector Location, float Radius);

	UActorPool* Pool;

	AActor* NavMeshBoundsVolume;
};
