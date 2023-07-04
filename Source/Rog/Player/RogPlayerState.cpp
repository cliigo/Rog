// Fill out your copyright notice in the Description page of Project Settings.


#include "RogPlayerState.h"

#include "Rog/Ability/RogAbilitySystemComponent.h"
#include "Rog/Character/CharacterAttributeSet.h"

ARogPlayerState::ARogPlayerState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
	CreateDefaultSubobject<UCharacterAttributeSet>(TEXT("CharacterAttributeSet"));
	
}
