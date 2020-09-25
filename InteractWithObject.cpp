// Developer: James Shaw

#include "InteractWithObject.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

/**
* This function allows interaction with an object (as a mesh). It sets
* the boolean state for the gravity and whether or not it is being held
* to true and false respectively before calling the SetSimulatePhysics
* function using an arrow operator to ensure the mesh abides to UE4's
* physical constraints.
*/
AInteractWithObject::AInteractWithObject() {
	PrimaryActorTick.bCanEverTick = true;
	HoldingState = false;
	GravityEffect = true;

	bool SimulatePhysics = true;

	AMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("A Mesh"));
	AMesh->SetSimulatePhysics(SimulatePhysics);

	RootComponent = AMesh;
}

/**
* This function allows a character to begin play. It calls its super
* constructor before intializing the character values. It stores an
* array of scene components aswell before iterating over them to find
* one(s) that matches the Holding Component specified in the header file.
*/
void AInteractWithObject::BeginPlay() {
	Super::BeginPlay();

	MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	PlayersCamera = MyCharacter->FindComponentByClass<UCameraComponent>();
	
	TArray<USceneComponent*> Comps;
	MyCharacter->GetComponents(Comps);
	int NumberOfComponents = Comps.Num();

	if (NumberOfComponents > 0) {
		for (auto& Comp : Comps) {
			if (Comp->GetName() == "Holding Component") {
				HoldingComp = Cast<USceneComponent>(Comp);
			}
		}
	}
}

/**
* This function is the Tick operation (running a certain amount of operations 
* in a frame) for the Object. It ensures that the Holding Component is updated
* to the appropriate location and rotation.
*/
void AInteractWithObject::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if ((HoldingState == true) && HoldingComp) {
		SetActorLocationAndRotation(HoldingComp->GetComponentLocation(), 
			HoldingComp->GetComponentRotation());
	}
}

/**
* This function sets the rotation of the actor in the world and uses Floating
* Point Quaternion to represent its axis in 3D space.
*/
void AInteractWithObject::ActorRotation() {
	ControlRotation = GetWorld()->GetFirstPlayerController()->GetControlRotation();
	SetActorRotation(FQuat(ControlRotation));
}

/**
* This function allows the object to be picked up, it reverses the
* state of whether or not the ball is being held before once again
* modifying the mesh to allow gravity, physics and collisions to
* operate upon it.
*/
void AInteractWithObject::PickObjectUp() {
	if (HoldingState == true) {
		HoldingState = false;
	}
	else {
		HoldingState = true;
	}

	bool setSimPhysStatus = false;
	if (HoldingState == true) {
		setSimPhysStatus = true;
	}
	else {
		setSimPhysStatus = false;
	}

	int AppliedForce = 100000;

	AMesh->SetEnableGravity(GravityEffect);
	AMesh->SetSimulatePhysics(setSimPhysStatus);
	AMesh->SetCollisionEnabled(HoldingState ? ECollisionEnabled::NoCollision : 
		ECollisionEnabled::QueryAndPhysics);

	if (!HoldingState) {
		ForwardVector = PlayersCamera->GetForwardVector();
		AMesh->AddForce(ForwardVector * AppliedForce * AMesh->GetMass());
	}
}