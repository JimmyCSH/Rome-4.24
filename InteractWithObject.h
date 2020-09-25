#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "InteractWithObject.generated.h"

UCLASS()
class ROME_API AInteractWithObject : public AActor {
	GENERATED_BODY()
	
public:	
	AInteractWithObject();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	FRotator ControlRotation;
	ACharacter* MyCharacter;
	UCameraComponent* PlayersCamera;
	FVector ForwardVector;
	bool HoldingState;
	bool GravityEffect;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* AMesh;

	UPROPERTY(EditAnywhere)
		USceneComponent* HoldingComp;

	UFUNCTION()
		void ActorRotation();

	UFUNCTION()
		void PickObjectUp();
};