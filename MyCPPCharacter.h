// Note: Commented out code is NOT a part of Sprint 1 and will be continued going into Sprint 2.
// Developer: James Shaw

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "MyCPPCharacter.generated.h"

UCLASS()
class ROME_API AMyCPPCharacter : public ACharacter {
	GENERATED_BODY()

public:
	AMyCPPCharacter();
	void Forward(float Orientation);
	void Right(float Orientation);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		USpringArmComponent* CamBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		UCameraComponent* MoveCam;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Walking/Sprinting")
		float SprintMulti;

protected:
	virtual void BeginPlay() override;

	void StartSprint();
	void StopSprint();
	void ToggleCrouch();

	// virtual void Tick(float DeltaSeconds) override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// float MinimumPitch, MaximumPitch;
	// FVector Start, ForwardMove, End, HoldingComp, LastRotation;
	// bool CanMove, Holding, Inspecting;
	// FHitResult Hit;
	// FComponentQueryParams DefaultComponentQueryParams;
	// FCollisionResponseParams DefaultResponseParams;

	// UPROPERTY(EditAnywhere)
		// AInteractWithObject* Current;

	// void Fire();
	// void Action();
	// void Inspect();
	// void Release();
	// void ToggleMove();
	// void ToggleItem();
};