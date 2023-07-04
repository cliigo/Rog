// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "RogGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class ROG_API URogGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()


public:
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Ability",  DisplayName = "OnAbilityAdded")
	void K2_OnAbilityAdded();

	UFUNCTION(BlueprintImplementableEvent, Category = "Ability", DisplayName = "OnAbilityRemoved")
	void K2_OnAbilityRemoved();
};
