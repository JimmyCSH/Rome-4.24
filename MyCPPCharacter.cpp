// Developer: James Shaw

#include "MyCPPCharacter.h"
#include "DrawDebugHelpers.h"

/**
* This function controls the character movements for rotating, jumping and
* having the camera follow in the approriate form. Note: Our character is currently not
* assigned a mesh, this is because assigning it with a mesh will come later on in
* Sprint 2.
*/
AMyCPPCharacter::AMyCPPCharacter() {
	PrimaryActorTick.bCanEverTick = true;

	// Set rotational movement and camera statuses...
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	bool BoomPawnControlRotation = true;
	bool CamPawnControlRotation = false;

	// Set values for movement...
	float RotateX = 0.0f;
	float RotateY = 540.0f;
	float RotateZ = 0.0f;
	float JumpV = 0.2f;
	float BoomD = 0.0f;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(RotateX, RotateY, RotateZ);
	GetCharacterMovement()->AirControl = JumpV;

	// Make a new camera...
	CamBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Boom"));
	CamBoom->SetupAttachment(RootComponent);
	CamBoom->TargetArmLength = BoomD;
	CamBoom->bUsePawnControlRotation = BoomPawnControlRotation;
	
	// Allow the camera to follow a character...
	MoveCam = CreateAbstractDefaultSubobject<UCameraComponent>(TEXT("Move Camera With User"));
	MoveCam->SetupAttachment(CamBoom, USpringArmComponent::SocketName);
	MoveCam->bUsePawnControlRotation = CamPawnControlRotation;

	// float ComponentDistance = 50.0f;
	// HoldingComponent = CreateDefaultSubobject<USceneComponent>(TEXT("HoldingComp"));
	// HoldingComponent->RelativeLocation.X = ComponentDistance;
	// HoldingComponent->SetupAttachment(GetMesh());

	SprintMulti = 1.8f;
}

// Function for enabling the character to move forwards and backwards...
void AMyCPPCharacter::Forward(float Orientation) {
	float YawRV1 = 0.0f;
	float YawRV2 = 0.0f;

	FRotator Rotate = Controller->GetControlRotation();
	FRotator YawRotation(YawRV1, Rotate.Yaw, YawRV2);

	FVector Dir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Dir, Orientation);
}

// Function for enabling the character to move left and right...
void AMyCPPCharacter::Right(float Orientation) {
	float YawRV1 = 0.0f;
	float YawRV2 = 0.0f;

	FRotator Rotate = Controller->GetControlRotation();
	FRotator YawRotation(YawRV1, Rotate.Yaw, YawRV2);

	FVector Dir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(Dir, Orientation);
}

// Overriding the BeginPlay function...
void AMyCPPCharacter::BeginPlay() {
	Super::BeginPlay();
}

// Make the new walking speed equal to the the sprint speed specified in the header class...
void AMyCPPCharacter::StartSprint() {
	GetCharacterMovement()->MaxWalkSpeed *= SprintMulti;
}

// If the character is sprinting, change back to the walking speed...
void AMyCPPCharacter::StopSprint() {
	GetCharacterMovement()->MaxWalkSpeed /= SprintMulti;
}

/**
* This function allows a character to crough by calling the built in functions and then
* assigning them to the character movement.
*/
void AMyCPPCharacter::ToggleCrouch() {
	bool EnableCrouching = true;

	if (GetCharacterMovement()->IsCrouching()) {
		UnCrouch();
	}
	else if (!GetCharacterMovement()->IsCrouching()) {
		Crouch();
		GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = EnableCrouching;
	}
}

// Overriding the Tick function...
void AMyCPPCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

/**
* Set up all of the key bindings for every movement of the character. Some functions are built
* into the UE4 C++ movement libraries already and so are just called when a button is pressed or
* released.
*/
void AMyCPPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &AMyCPPCharacter::Forward);
	PlayerInputComponent->BindAxis("Right", this, &AMyCPPCharacter::Right);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AMyCPPCharacter::StartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AMyCPPCharacter::StopSprint);
	PlayerInputComponent->BindAction("ToggleCrouch", IE_Pressed, this, &AMyCPPCharacter::ToggleCrouch);
}