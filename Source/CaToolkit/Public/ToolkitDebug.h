#pragma once

#include "Engine/Engine.h"
#include "Misc/MessageDialog.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"

static  void Print(const FString& message, const FColor& color)
{
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, color, message);
	}
}

static  void PrintLog(const FString& message)
{
	UE_LOG(LogTemp,Warning, TEXT("%s"), *message);
}

static  EAppReturnType::Type ShowMsgDialog(EAppMsgType::Type msgType, const FString& message,bool bShowMsgAsWarning= true)
{
	if(bShowMsgAsWarning)
	{
		FText msgTitle = FText::FromString(TEXT("Warning"));
		return FMessageDialog::Open(msgType, FText::FromString(message), &msgTitle);
	}
	return FMessageDialog::Open(msgType, FText::FromString(message));
}

static  void ShowNotifyInfo(const FString& message)
{
	FNotificationInfo notifyInfo(FText::FromString(message));
	notifyInfo.bUseLargeFont = true;
	notifyInfo.FadeOutDuration = 7.f;

	FSlateNotificationManager::Get().AddNotification(notifyInfo);
}