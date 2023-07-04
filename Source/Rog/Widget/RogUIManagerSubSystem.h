// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "RogUIManagerSubSystem.generated.h"



/*
 *
 */
struct FRogUIData : TSharedFromThis<FRogUIData>
{
public:
	/** The extension point this extension is intended for. */
	FGameplayTag WidgetTag;
	int32 Priority = INDEX_NONE;
	TWeakObjectPtr<UObject> ContextObject;
	//Kept alive by UUIExtensionSubsystem::AddReferencedObjects
	UObject* Data = nullptr;
};


/**
 * 
 */
USTRUCT(BlueprintType)
struct UIEXTENSION_API FRogUIHandle
{
	GENERATED_BODY()

public:
	FRogUIHandle() {}

	void Unregister();

	bool IsValid() const { return DataPtr.IsValid(); }

	bool operator==(const FRogUIHandle& Other) const { return DataPtr == Other.DataPtr; }
	bool operator!=(const FRogUIHandle& Other) const { return !operator==(Other); }

	friend FORCEINLINE uint32 GetTypeHash(FRogUIHandle Handle)
	{
		return PointerHash(Handle.DataPtr.Get());
	}

private:
	TWeakObjectPtr<URogUIManagerSubSystem> ExtensionSource;

	TSharedPtr<FRogUIData> DataPtr;

	friend URogUIManagerSubSystem;

	FRogUIHandle(URogUIManagerSubSystem* InExtensionSource, const TSharedPtr<FRogUIData>& InDataPtr) : ExtensionSource(InExtensionSource), DataPtr(InDataPtr) {}
};



/**
 * 
 */
UCLASS()
class ROG_API URogUIManagerSubSystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "UI Extension", meta = (DisplayName = "Register UI "))
	FRogUIHandle K2_RegisterWidget(FGameplayTag WidgetTag, TSubclassOf<UUserWidget> WidgetClass, int32 Priority = -1);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "UnRegister UI")
	void K2_UnRegisterWidget(const FRogUIHandle& RogUIHandle);

	void UnRegisterWidget(const FRogUIHandle& RogUIHandle);

private:
	TMap<FGameplayTag,TSharedPtr<FRogUIData>> RogUIDict;
};



