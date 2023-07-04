// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EquipBase.h"
#include "UObject/Object.h"
#include "EquipSlot.generated.h"

/**
 * 
 */
UCLASS()
class ROG_API UEquipSlot : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool AddEquip(UEquipBase* equipItem);

	UFUNCTION(BlueprintCallable)
	bool RemoveEquip(UEquipBase* equipItem);
	
public:
	
	/**
	 * 槽位序号
	 */
	UPROPERTY(BlueprintReadOnly)
	int32 SlotIndex;
	
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UEquipBase> EquipItem;
};
