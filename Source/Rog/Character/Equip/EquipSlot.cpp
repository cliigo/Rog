// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipSlot.h"

bool UEquipSlot::AddEquip(UEquipBase* equipItem)
{
	if(IsValid(equipItem))
	{
		this->EquipItem = equipItem;
		return true;
	}
	return false;
}

bool UEquipSlot::RemoveEquip(UEquipBase*  equipItem)
{
	if(IsValid(equipItem) && equipItem == this->EquipItem)
	{
		this->EquipItem = nullptr;
		return true;
	}
	return false;
}
