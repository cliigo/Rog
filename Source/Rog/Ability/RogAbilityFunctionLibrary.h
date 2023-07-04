// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RogAbilitySet.h"
#include "RogAbilityFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ROG_API URogAbilityFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Ability")
	static void  AddAbilitySetToASC(class URogAbilitySystemComponent* ASC, const FRogAbilitySet& InAbilitySets,FRogAbilitySet_GrantedHandles& OutGrantedHandles, UObject*SourceObject = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Ability")
	static void TakeFormAbilitySystem(URogAbilitySystemComponent* ASC,UPARAM(ref) FRogAbilitySet_GrantedHandles& InGrantedHandles);
};
