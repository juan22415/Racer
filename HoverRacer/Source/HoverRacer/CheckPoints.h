// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "CheckPointMesh.h"
#include "Components/AudioComponent.h"
#include "CheckPoints.generated.h"

UCLASS()
class HOVERRACER_API ACheckPoints : public ATriggerBox
{
	GENERATED_BODY()
	
protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// constructor sets default values for this actor's properties
	ACheckPoints();

	 	// overlap begin function
	 	UFUNCTION()
	 	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	 	// overlap end function
	 	UFUNCTION()
	 	void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
		
		UPROPERTY(EditAnywhere)
		class AActor* SpecificActor;

		UPROPERTY(EditAnywhere)
		class ACheckPointMesh* CheckPointMesh;

		UPROPERTY(EditAnywhere,BlueprintReadOnly)
		UAudioComponent *AudioComponent;

		bool IsActive = false;

		void SetActiveColor();
		void SetDisableColor();

};
