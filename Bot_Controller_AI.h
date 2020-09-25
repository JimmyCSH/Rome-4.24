// Developer: James Shaw

#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "Bot_Controller_AI.generated.h"

UCLASS()
class ROME_API ABot_Controller_AI : public AAIController {
	GENERATED_BODY()

public:
	ABot_Controller_AI();

	// Override the built in functions required...
	virtual void Tick(float DeltaSeconds) override;
	virtual void OnPossess(APawn* aPawn) override;
	virtual void BeginPlay() override;
	virtual FRotator GetControlRotation() const override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Bot)
		float ViewAge = 10.0f; // Amount of time the bot view is active for

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Bot)
		float ViewRadius = 600.0f; // Radius for the bot to move within (green zone)

	float TotalLoseSight = ViewRadius + 100.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Bot)
		float Lose = TotalLoseSight; // Radius set for bot to lose sight (red zone)

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Bot)
		float FOV = 90.0f; // The Field of View

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Bot)
		class UAISenseConfig_Sight* SightConfig;

protected:
	UFUNCTION()
		void OnPawnDetected(const TArray<AActor*> &DetectedPawns);
};