// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RogAbilitySystemComponent.h"
#include "RogAttributeSet.h"
#include "RogGameplayAbility.h"
#include "UObject/Object.h"
#include "RogAbilitySet.generated.h"


USTRUCT(BlueprintType)
struct FRogAbilitySet_GameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<URogGameplayAbility> Ability = nullptr;

	UPROPERTY(EditDefaultsOnly)
	int32 AbilityLevel = 1;

	// ProcessInput for ability
	UPROPERTY(EditDefaultsOnly, Meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly)
	bool IsActive; //是否激活
};


USTRUCT()
struct FRogAbilitySet_GameplayEffect
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayEffect> GameplayEffect = nullptr;

	UPROPERTY(EditDefaultsOnly)
	float EffectLevel = 1.0f;
};

USTRUCT(BlueprintType)
struct FRogAbilitySet_AttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<URogAttributeSet> AttributeSet;
	
};

USTRUCT(BlueprintType)
struct FRogAbilitySet_GrantedHandles
{
	GENERATED_BODY()

public:
	void AddAbilitySpecHandle(const FGameplayAbilitySpecHandle& AbilitySpecHandle);
	void AddEffectSpecHandle(const FActiveGameplayEffectHandle& EffectSpecHandle);
	void AddAttributeSet(UAttributeSet* AttributeSet);

	void TaskFormAbilitySystem(URogAbilitySystemComponent* RogASC) ; 



protected:

	UPROPERTY()
	TArray<FGameplayAbilitySpecHandle> AbilitySpecHandles;
	UPROPERTY()
	TArray<FActiveGameplayEffectHandle> EffectSpecHandles;

	UPROPERTY()
	TArray<TObjectPtr<UAttributeSet>> AttributeSets;
};

/**
 * 
 */
USTRUCT(BlueprintType)
struct ROG_API FRogAbilitySet 
{
	GENERATED_BODY()

public:
	
	void GiveToAbilitySystem(URogAbilitySystemComponent* RogASC,FRogAbilitySet_GrantedHandles* OutGrantedHandles, UObject*SourceObject = nullptr) const;

protected:

	UPROPERTY(EditDefaultsOnly, Category="Gameplay Abilitys",meta=(TitleProperty=Ability))
	TArray<FRogAbilitySet_GameplayAbility> GrantedGameplayAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay Effects", meta = (TitleProperty = GameplayEffect))
	TArray<FRogAbilitySet_GameplayEffect> GrantedGameplayEffects;

	UPROPERTY(EditDefaultsOnly, Category = "AttributeSet", meta = (TitleProperty = AttributeSet));
	TArray<FRogAbilitySet_AttributeSet> GrantedAttributeSets;
};
