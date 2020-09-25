// Developer: James Shaw
// Developer: Jaya Gascon

#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/Engine.h"
#include "MyTestBPCPP.generated.h"

/**
 * This file is just a test for providing output to the console log when
 * someone is playing the game and a certain button is pressed. It is
 * largely a test to see how blueprint functions can be called from
 * C++ files.
 */
UCLASS()
class ROME_API UMyTestBPCPP : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Print to Console Log")
		static void MyConsoleLogFunction(FString aString);

	UFUNCTION(BlueprintCallable, Category = "Print to Screen")
		static void PrintTextToScreen();

	UFUNCTION(BlueprintCallable, Category = "Print to Screen if in Position")
		static void PrintLocationAndInformation(FString Line1, FString Line2, FString Line3);
};