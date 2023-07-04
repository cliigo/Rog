// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Rog/Ability/RogAttributeSet.h"
#include "CharacterAttributeSet.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ROG_API UCharacterAttributeSet : public URogAttributeSet
{
	GENERATED_UCLASS_BODY()

public:

	UCharacterAttributeSet();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Character", meta = (HideFromModifiers))
	mutable float CurHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Character", meta = (HideFromModifiers))
	mutable float MaxHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Character", meta = (HideFromModifiers))
	mutable float PhysicalResistance;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Character", meta = (HideFromModifiers))
	mutable float ElementalResistance;
	
};
