// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObjMgrSubSystem.h"


UGameObjMgrSubSystem::UGameObjMgrSubSystem()
{
	
}

void UGameObjMgrSubSystem::RegInstance(UWorld* world, IGameObj* GameObj)
{
	if(world == nullptr || GameObj == nullptr)
		return;
	const auto mgr = world->GetSubsystem<UGameObjMgrSubSystem>();
	if(mgr != nullptr)
	{
		mgr->RegInstance(GameObj);
	}
}

void UGameObjMgrSubSystem::UnRegInstance(UWorld* world, IGameObj* GameObj)
{
	if(world == nullptr || GameObj == nullptr)
		return;
	const auto mgr = world->GetSubsystem<UGameObjMgrSubSystem>();
	if(mgr != nullptr)
	{
		mgr->UnRegInstance(GameObj);
	}
}


void UGameObjMgrSubSystem::RegInstance(IGameObj* GameObj)
{

	if(GameObj != nullptr)
	{
		GameObj->InstanceId = ++createInstanceId;
		instanceMap.Add(GameObj->InstanceId, GameObj);
	}
	
}

void UGameObjMgrSubSystem::UnRegInstance(IGameObj* GameObj)
{
	if(GameObj != nullptr)
	{
		int id = GameObj->InstanceId;
		instanceMap.Remove(id);
		GameObj->InstanceId = 0;
	}
}


IGameObj* UGameObjMgrSubSystem::GetGameObj(int instanceId)
{
	auto ptr = instanceMap.Find(instanceId); 
	if(ptr != nullptr)
		return *ptr;
	return  nullptr;
}


