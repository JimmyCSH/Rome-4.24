// Resource: https://docs.unrealengine.com/en-US/Programming/Tutorials/PlayerInput/index.html
// Developer: James Shaw

#include "BotDirection.h"
#include "Bot_Character_AI.h"

/**
* This function intializes the root component (component for defining actor/pawn transformation) and
* connects it to the sphere that acts as a waypoint.
*/
ABotDirection::ABotDirection() {
	PrimaryActorTick.bCanEverTick = true;
	RComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(RComponent);

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	SphereComponent->SetupAttachment(GetRootComponent());
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ABotDirection::EnterCharacter);
}

/**
* This method initializes the 'waypoint' and calls the bot from the Bot_Character_AI class to
* travel to the next waypoint.
*/
void ABotDirection::EnterCharacter(UPrimitiveComponent* Overlap, AActor* AnyActor,
	UPrimitiveComponent* OtherComp, int32 OtherIndex, bool bSweeper, const FHitResult & SResult) {
	ABot_Character_AI* OurBot = nullptr;

	if (AnyActor == nullptr) {
		// This should not be the case!
	}
	else {
		OurBot = Cast<ABot_Character_AI>(AnyActor);
	}

	if (OurBot == nullptr) {
		// This should not be the case!
	}
	else {
		OurBot->NextWayPoint = NextWayPoint;
	}
}

// Overrides the Begin Play function...
void ABotDirection::BeginPlay() {
	Super::BeginPlay();
}

// Overrides the Tick function...
void ABotDirection::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}