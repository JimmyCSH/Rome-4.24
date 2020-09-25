// Resource: https://docs.unrealengine.com/en-US/Programming/Tutorials/PlayerInput/index.html
// Developer: James Shaw

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "BotDirection.generated.h"

UCLASS()
class ROME_API ABotDirection : public AActor {
	GENERATED_BODY()
	
public:	
	ABotDirection();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ABotDirection* NextWayPoint;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USceneComponent* RComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USphereComponent* SphereComponent;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		// https://www.youtube.com/watch?v=nXFX3NfTbzI
		void EnterCharacter(UPrimitiveComponent* Overlap, AActor* AnyActor, UPrimitiveComponent* OtherComp,
			int32 OtherIndex, bool bSweeper, const FHitResult & SResult);
};