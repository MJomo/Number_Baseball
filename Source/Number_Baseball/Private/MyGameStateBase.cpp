#include "MyGameStateBase.h"
#include "Kismet/GameplayStatics.h"
#include "MyPlayerController.h"

void AMyGameStateBase::MulticastRPCBroadcastLoginMessage_Implementation(const FString& InNameString)
{
	if (HasAuthority() == false)
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		if (IsValid(PC) == true)
		{
			AMyPlayerController* MYPC = Cast<AMyPlayerController>(PC);
			if (IsValid(MYPC) == true)
			{
				FString NotificationString = InNameString + TEXT(" gas joined the game.");
				MYPC->PrintChatMessageString(NotificationString);
			}
		}
	}
}