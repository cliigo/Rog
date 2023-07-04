// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ItemData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FItemData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	FText ItemName;

	UPROPERTY(BlueprintReadWrite)
	FSoftObjectPath ItemIconPath;
	
	UPROPERTY(BlueprintReadWrite)
	int32 ItemCount;
};
