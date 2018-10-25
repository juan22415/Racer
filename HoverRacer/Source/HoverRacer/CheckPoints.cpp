

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))


#include "CheckPoints.h"


ACheckPoints::ACheckPoints()
{
	//Register Events
	OnActorBeginOverlap.AddDynamic(this, &ACheckPoints::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ACheckPoints::OnOverlapEnd);
	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
	AudioComponent->Deactivate();
	
}


// Called when the game starts or when spawned
void ACheckPoints::BeginPlay()
{
	Super::BeginPlay();

	AudioComponent->Deactivate();
	FVector Location = GetActorLocation();
	CheckPointMesh->SetLocation(Location);
}


 void ACheckPoints::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
 {
     // check if Actors do not equal nullptr and that 
     if (OtherActor && (OtherActor != this) && OtherActor == SpecificActor) {
         // print to screen using above defined method when actor enters trigger box
         print("Overlap Begin");
         //printFString("Overlapped Actor = %s", *OverlappedActor->GetName());
		 AudioComponent->Activate();
		 

     }
 }

void ACheckPoints::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this) && OtherActor == SpecificActor) {
		// print to screen using above defined method when actor leaves trigger box
		//print("Overlap Ended");
		//printFString("%s has left the Trigger Box", *OtherActor->GetName());
		IsActive = false;
		CheckPointMesh->SetDisableColor();
	}
}

void ACheckPoints::SetActiveColor()
{
	CheckPointMesh->SetActiveColor();
}

void ACheckPoints::SetDisableColor()
{
	CheckPointMesh->SetDisableColor();
}
