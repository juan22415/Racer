// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CheckPoints.h"
#include "Components/TimelineComponent.h"
#include "CheckPointManager.generated.h"

UCLASS()
class HOVERRACER_API ACheckPointManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACheckPointManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnyWhere)
	TArray<ACheckPoints*> CheckpointsArray;
	
	void SetInitialCheckpoint();
	void DisableActiveCheckpoint();
	void ActiveNextCheckpoint();
	void ResetTime();
	void CheckBestLapTime();

	int32 CurrentActiveCheckpoint=0;
	float Timer = 0;
	float BestLapTime = 100;

};
