// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageWorldSystem.h"

#include "Rog/GameObj/GameObjMgrSubSystem.h"

void UDamageWorldSystem::DoDamage(int attackerId, int targetId, const FBulletData& BulletInfo)
{
	auto objMgr = GetWorld()->GetSubsystem<UGameObjMgrSubSystem>();
	if(objMgr == nullptr)
		return;
	
}
