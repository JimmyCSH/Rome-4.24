// Developer - James Shaw

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Bot_Character_AI.generated.h"

UCLASS()
class ROME_API ABot_Character_AI : public ACharacter {
	GENERATED_BODY()

public:
	ABot_Character_AI();

	// Create a new Property allowed to be edited anywhere and added in blueprints...
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class ABotDirection* NextWayPoint;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// Override the player input to create our own methods...
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};