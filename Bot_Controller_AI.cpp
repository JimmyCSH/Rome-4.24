// Developer: James Shaw

#include "Bot_Controller_AI.h"
#include "Bot_Character_AI.h"
#include "BotDirection.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

/**
* The constructor for the bot controller initializes the booleans to enable the character
* move within the world. It configures the sight range of the bot (these values are the
* ranges in which the bot performs the defined movements) before calling a pointer to that
* variable for initializion with the prefefined GetPerceptionComponent function.
*/
ABot_Controller_AI::ABot_Controller_AI() {
	bool AllowBotTick = true;
	bool EnableAllDetection = true;
	PrimaryActorTick.bCanEverTick = AllowBotTick;

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Configuration"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));

	SightConfig->LoseSightRadius = Lose;
	SightConfig->PeripheralVisionAngleDegrees = FOV;
	SightConfig->SightRadius = ViewRadius;
	SightConfig->SetMaxAge(ViewAge);
	SightConfig->DetectionByAffiliation.bDetectEnemies = EnableAllDetection;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = EnableAllDetection;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = EnableAllDetection;

	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &ABot_Controller_AI::OnPawnDetected);
	GetPerceptionComponent()->ConfigureSense(*SightConfig);
}

/**
* This function simply geta a character pointer for the current bot and ensures that
* it moves to the next way point within a specified range.
*/
void ABot_Controller_AI::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	ABot_Character_AI* BotCharacter = Cast<ABot_Character_AI>(GetPawn());

	if (BotCharacter->NextWayPoint == nullptr) {
		// This should not happen!
	}
	else {
		MoveToActor(BotCharacter->NextWayPoint, 2.0f);
	}
}

// Overriding the OnPosses function...
void ABot_Controller_AI::OnPossess(APawn* aPawn) {
	Super::OnPossess(aPawn);
}

// Overriding the BeginPlay function...
void ABot_Controller_AI::BeginPlay() {
	Super::BeginPlay();
}

/**
* This function intializes variables for a 3D plane of rotation (x, y, z) and
* allows the character to have default rotation settings for its movement.
*/
FRotator ABot_Controller_AI::GetControlRotation() const {
	float RotateXRate = 0.0f;
	float RotateYRate = 0.0f;
	float RotateZRate = 0.0f;

	if (GetPawn() == nullptr) {
		return FRotator(RotateXRate, RotateYRate, RotateZRate);
	}

	return FRotator(RotateXRate, GetPawn()->GetActorRotation().Yaw, 0.0f);
}

// Empty function simply to reduce errors...
void ABot_Controller_AI::OnPawnDetected(const TArray<AActor*>& DetectedPawns) {

}