// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "MyUserWidget.h"
#include "EngineUtils.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Number_Baseball.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameModeBase.h"
#include "MyPlayerState.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (IsLocalController() == false)
	{
		return;
	}

	FInputModeUIOnly InputModeUIOnly;
	SetInputMode(InputModeUIOnly);

	if (IsValid(ChatInputWidgetClass) == true)
	{
		ChatInputWidgetInstance = CreateWidget<UMyUserWidget>(this, ChatInputWidgetClass);
		if (IsValid(ChatInputWidgetInstance) == true)
		{
			ChatInputWidgetInstance->AddToViewport();
		}
	}
}

void AMyPlayerController::SetChatMessageString(const FString& InChatMessageString)
{
	ChatMessageString = InChatMessageString;

	//PrintChatMessageString(ChatMessageString);
	if (IsLocalController() == true)
	{
		//ServerRPCPrintChatMessageString(InChatMessageString);

		AMyPlayerState* MYPS = GetPlayerState<AMyPlayerState>();
		if (IsValid(MYPS) == true)
		{
			//FString CombinedMessageString = MYPS->PlayerNameString + TEXT(": ") + InChatMessageString;
			FString CombinedMessageString = MYPS->GetPlayerInfoString() + TEXT(": ") + InChatMessageString;

			ServerRPCPrintChatMessageString(CombinedMessageString);
		}
	}
}

void AMyPlayerController::PrintChatMessageString(const FString& InChatMessageString)
{
	//UKismetSystemLibrary::PrintString(this, ChatMessageString, true, true, FLinearColor::Red, 5.0f);
	
	//로깅용
	FString NetModeString = ChatXFunctionLibrary::GetNetModeString(this);
	FString CombinedMessageString = FString::Printf(TEXT("%s: %s"), *NetModeString, *InChatMessageString);

	ChatXFunctionLibrary::MyPrintString(this, CombinedMessageString, 10.f);
}

void AMyPlayerController::ClientRPCPrintChatMessageString_Implementation(const FString& InChatMessageString)
{
	PrintChatMessageString(InChatMessageString);
}

void AMyPlayerController::ServerRPCPrintChatMessageString_Implementation(const FString& InChatMessageString)
{
	/*for (TActorIterator<AMyPlayerController> It(GetWorld()); It; ++It)
	{
		AMyPlayerController* MyPlayerController = *It;
		if (IsValid(MyPlayerController) == true)
		{
			MyPlayerController->ClientRPCPrintChatMessageString(InChatMessageString);
		}
	}*/ // ^^^^^^^^ MyGameModeBase.cpp로 옮겨짐

	AGameModeBase* GM = UGameplayStatics::GetGameMode(this);
	if (IsValid(GM) == true)
	{
		AMyGameModeBase* Number_Baseball_GM = Cast<AMyGameModeBase>(GM);
		if (IsValid(Number_Baseball_GM) == true)
		{
			Number_Baseball_GM->PrintChatMessageString(this, InChatMessageString);
		}
	}

}
