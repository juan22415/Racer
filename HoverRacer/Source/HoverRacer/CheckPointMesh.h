// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/StaticMesh.h"
#include "Components/MeshComponent.h"
#include "CheckPointMesh.generated.h"

UCLASS()
class HOVERRACER_API ACheckPointMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACheckPointMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere)
	UMaterialInterface * DisableMaterial;

	UPROPERTY(EditAnywhere)
	UMaterialInterface * ActiveMaterial;

	void SetDisableColor();
	void SetActiveColor();

	void SetLocation(FVector location);
	
};
