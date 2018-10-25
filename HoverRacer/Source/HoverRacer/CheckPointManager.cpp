// Fill out your copyright notice in the Description page of Project Settings.
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

#include "CheckPointManager.h"
#include "DrawDebugHelpers.h"


// Sets default values
ACheckPointManager::ACheckPointManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACheckPointManager::BeginPlay()
{
	Super::BeginPlay();
	SetInitialCheckpoint();
}

// Called every frame
void ACheckPointManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timer += DeltaTime;


	if (!CheckpointsArray[CurrentActiveCheckpoint]->IsActive)
	{
		DisableActiveCheckpoint();
		ActiveNextCheckpoint();
	}

}


void ACheckPointManager::SetInitialCheckpoint()
{
	
	CheckpointsArray[CurrentActiveCheckpoint]->IsActive = true;
	CheckpointsArray[CurrentActiveCheckpoint]->SetActiveColor();
	for (int i = 1; i < CheckpointsArray.Num(); i++)
	{
		CheckpointsArray[i]->SetActorEnableCollision(false);
		CheckpointsArray[i]->SetDisableColor();
	}
}

void ACheckPointManager::DisableActiveCheckpoint()
{
	CheckpointsArray[CurrentActiveCheckpoint]->SetActorEnableCollision(false);
	CurrentActiveCheckpoint++;
	if (CurrentActiveCheckpoint == CheckpointsArray.Num())
		{ 
			CurrentActiveCheckpoint = 0;
			CheckBestLapTime();
			printFString("Lap Time: %f ", Timer);
			printFString("Best Lap Time: %f ", BestLapTime);
			ResetTime();
		}
}

void ACheckPointManager::ActiveNextCheckpoint()
{
	CheckpointsArray[CurrentActiveCheckpoint]->IsActive = true;
	CheckpointsArray[CurrentActiveCheckpoint]->SetActorEnableCollision(true);
	CheckpointsArray[CurrentActiveCheckpoint]->SetActiveColor();
}

void ACheckPointManager::ResetTime()
{
	Timer = 0;
}

void ACheckPointManager::CheckBestLapTime()
{
	if (Timer < BestLapTime)
	{
		BestLapTime = Timer;
	}
}

