// Developer: James Shaw
// Developer: Jaya Gascon

#include "MyTestBPCPP.h"

void UMyTestBPCPP::MyConsoleLogFunction(FString aString) {
	UE_LOG(LogTemp, Log, TEXT("The output is:  %s"), *aString)
}

void UMyTestBPCPP::PrintTextToScreen() {
	if (GEngine) {
		// Give a welcome on screen for the user to quickly view some basic instructions...
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Use W, A, S, D to move Forward, Left, Back & Right."));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Press Ctrl to Crouch & Shift to Sprint."));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Welcome to Pax Romana!"));
	}
}

void UMyTestBPCPP::PrintLocationAndInformation(FString Line1, FString Line2, FString Line3) {
	if (GEngine) {
		// Print some information regarding the characters location...
		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Blue, FString::Printf(TEXT("%s"), *Line3));
		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Blue, FString::Printf(TEXT("%s"), *Line2));
		GEngine->AddOnScreenDebugMessage(-1, 20.0f, FColor::Blue, FString::Printf(TEXT("%s"), *Line1));
	}
}