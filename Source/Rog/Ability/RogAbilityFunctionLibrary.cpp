// Fill out your copyright notice in the Description page of Project Settings.


#include "RogAbilityFunctionLibrary.h"

#include "RogAbilitySet.h"
#include "Rog/Character/RogCharacter.h"

void URogAbilityFunctionLibrary::AddAbilitySetToASC(URogAbilitySystemComponent* ASC,
														const FRogAbilitySet& InAbilitySets, FRogAbilitySet_GrantedHandles& OutGrantedHandles,
														UObject* SourceObject)
{
	InAbilitySets.GiveToAbilitySystem(ASC, &OutGrantedHandles, SourceObject);
}

void URogAbilityFunctionLibrary::TakeFormAbilitySystem(URogAbilitySystemComponent* ASC,  FRogAbilitySet_GrantedHandles& InGrantedHandles)
{
	InGrantedHandles.TaskFormAbilitySystem(ASC);
}
