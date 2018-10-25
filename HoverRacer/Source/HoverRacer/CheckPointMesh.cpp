#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))


#include "CheckPointMesh.h"


// Sets default values
ACheckPointMesh::ACheckPointMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MeshComponent->SetupAttachment(RootComponent);
	RootComponent = MeshComponent;
}

// Called when the game starts or when spawned
void ACheckPointMesh::BeginPlay()
{
	Super::BeginPlay();
	//MeshComponent->SetMaterial(0, DisableMaterial);
	
}

// Called every frame
void ACheckPointMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACheckPointMesh::SetDisableColor()
{
	MeshComponent->SetMaterial(0, DisableMaterial);
}

void ACheckPointMesh::SetActiveColor()
{
	MeshComponent->SetMaterial(0, ActiveMaterial);
}

void ACheckPointMesh::SetLocation(FVector location)
{
	MeshComponent->SetRelativeLocation(location);
	MeshComponent->SetWorldLocation(location);

}


