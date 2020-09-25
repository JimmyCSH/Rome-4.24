// Developer - James Shaw

#include "Bot_Character_AI.h"
#include "GameFramework/CharacterMovementComponent.h"

/**
* The constructor initializes the character to allow rotation and movement.
*/
ABot_Character_AI::ABot_Character_AI() {
	PrimaryActorTick.bCanEverTick = true;
	
	// Allow the character to move in the direction that it is facing...
	bool AlignCharacterWithDirection = true;

	// Set the default rate that the character rotates at...
	float RotateXRate = 0.0f;
	float RotateYRate = 600.0f;
	float RotateZRate = 0.0f;

	// Allow character to rotate using values above...
	GetCharacterMovement()->bOrientRotationToMovement = AlignCharacterWithDirection;
	GetCharacterMovement()->RotationRate = FRotator(RotateXRate, RotateYRate, RotateZRate);
}

/**
* BeginPlay simply calls its super (Functionality for starting a character from
* the built in Character super class.
*/
void ABot_Character_AI::BeginPlay() {
	Super::BeginPlay();
}

/**
* The standard Tick function once again simply calls the super function to tick after a
* certain amount of time.
*/
void ABot_Character_AI::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

/**
* This function sets up the player input by once again calling its super function.
*/
void ABot_Character_AI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}