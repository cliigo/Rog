// Fill out your copyright notice in the Description page of Project Settings.


#include "RogUIManagerSubSystem.h"

#include "Blueprint/UserWidget.h"
#include "Rog/RogLog.h"

void FRogUIHandle::Unregister()
{
	if(ExtensionSource.IsValid())
	{
		ExtensionSource->UnRegisterWidget(*this);
	}
	
}

FRogUIHandle URogUIManagerSubSystem::K2_RegisterWidget(FGameplayTag WidgetTag,
														TSubclassOf<UUserWidget> WidgetClass, int32 Priority)
{
	if(!IsValid(WidgetClass))
	{
		UE_LOG(LogRog, Warning, TEXT("Invalid WidgetClass"));
		return FRogUIHandle();
	}
	if(!WidgetTag.IsValid())
	{
		UE_LOG(LogRog,Warning,TEXT("Invalid WidgetTag"));
		return FRogUIHandle();
	}
	if(RogUIDict.Find(WidgetTag))
	{
		UE_LOG(LogRog,Warning,TEXT("WidgetTag already registered"));
		return FRogUIHandle();
	}
	UUserWidget* widgetPtr = CreateWidget(GetWorld(),WidgetClass);
	if(!IsValid(widgetPtr))
	{
		UE_LOG(LogRog,Warning,TEXT("Failed to create widget"));
		return FRogUIHandle();
	}

	widgetPtr->AddToViewport(Priority);

	TSharedPtr<FRogUIData> UIData = MakeShared<FRogUIData>();
	UIData->WidgetTag = WidgetTag;
	UIData->Priority = Priority;

	
	UIData->Data = widgetPtr;
	UIData->ContextObject = this;
	
	RogUIDict.Add(WidgetTag,UIData);
	return FRogUIHandle(this,UIData);
}

void URogUIManagerSubSystem::K2_UnRegisterWidget(const FRogUIHandle& RogUIHandle)
{
	UnRegisterWidget(RogUIHandle);
}

void URogUIManagerSubSystem::UnRegisterWidget(const FRogUIHandle& RogUIHandle)
{

	if(RogUIHandle.IsValid())
	{
		if(RogUIHandle.ExtensionSource != this)
		{
			UE_LOG(LogRog,Error,TEXT("Invalid RogUIHandle"));
			return;
		}
		TSharedPtr<FRogUIData> UIData = RogUIHandle.DataPtr;
		if(!RogUIDict.Remove(UIData->WidgetTag))
		{
			UE_LOG(LogRog,Error,TEXT("Failed to remove widget"));
			return;
		}
		UUserWidget* Widget = Cast<UUserWidget>(UIData->Data);
		Widget->RemoveFromParent();
		UIData->Data = nullptr;
		UIData->ContextObject = nullptr;
		RogUIDict.Remove(UIData->WidgetTag);
	}
}