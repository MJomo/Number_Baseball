// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

class AMyPlayerController;
/**
 * 
 */
UCLASS()
class NUMBER_BASEBALL_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	virtual void OnPostLogin(AController* NewPlayer) override;

	FString GenerateSecretNumber();

	bool IsGuessNumverString(const FString& InNumberString);

	FString JudgeResult(const FString& InSecretNumberString, const FString& InGuessNumberString);

	virtual void BeginPlay() override;

	void PrintChatMessageString(AMyPlayerController* InChattingPlayerController, const FString& InChatMessageString);



protected:
	FString SecretNumberString;

	TArray<TObjectPtr<AMyPlayerController>> AllPlayerControllers;
};
