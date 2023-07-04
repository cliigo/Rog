// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAttributeSet.h"

#include "Net/UnrealNetwork.h"

UCharacterAttributeSet::UCharacterAttributeSet(const FObjectInitializer& ObjectInitializer)
{
	CurHp = 0;
	MaxHp =100;
	PhysicalResistance = 0;
	ElementalResistance = 0;
}

void UCharacterAttributeSet::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	DISABLE_ALL_CLASS_REPLICATED_PROPERTIES(UCharacterAttributeSet, EFieldIteratorFlags::IncludeSuper);
	
	DOREPLIFETIME( UCharacterAttributeSet, CurHp);
	DOREPLIFETIME( UCharacterAttributeSet, MaxHp);
	DOREPLIFETIME( UCharacterAttributeSet, PhysicalResistance);
	DOREPLIFETIME( UCharacterAttributeSet, ElementalResistance);
	
	
}

UCharacterAttributeSet::UCharacterAttributeSet()
{

	

}

