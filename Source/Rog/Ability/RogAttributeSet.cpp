// Fill out your copyright notice in the Description page of Project Settings.


#include "RogAttributeSet.h"

#include "RogAbilitySystemComponent.h"



class URogAbilitySystemComponent;
class UWorld;

URogAttributeSet::URogAttributeSet()
{
	
}

UWorld* URogAttributeSet::GetWorld() const
{
	const UObject* Outer = GetOuter();
	check(Outer);
	return Outer->GetWorld();
}


URogAbilitySystemComponent* URogAttributeSet::GetRogAbilitySystemComponent() const
{
	return Cast<URogAbilitySystemComponent>(GetOwningAbilitySystemComponent());
}

