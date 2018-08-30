// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable,Category=Spawn)
	void PlaceActors(TSubclassOf<AActor> ToSpawn,int MinSpawn,int MaxSpawn,int Radius);
	
	void PlaceActor(TSubclassOf<AActor> ToSpawn, FVector SpawnPoint);

	bool FindEmptyLocation(OUT FVector& OutLocation, float Radius);

	bool CanSpawnAtLocation(FVector Location, float Radius);
};
