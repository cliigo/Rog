// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Equip/EquipSlot.h"
#include "CharacterEquipComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ROG_API UCharacterEquipComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCharacterEquipComponent();



public:
	UPROPERTY(BlueprintReadWrite, Category = "Equip")
	TArray<TObjectPtr<UEquipSlot>> EquipSlots;
};
