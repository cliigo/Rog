// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameObj.h"

#include "Subsystems/WorldSubsystem.h"
#include "GameObjMgrSubSystem.generated.h"


UCLASS(Blueprintable)
class ROG_API UGameObjMgrSubSystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UGameObjMgrSubSystem();

	static void RegInstance(UWorld* world,IGameObj* GameObj);
	static void UnRegInstance(UWorld* world,IGameObj* GameObj);
	
	void RegInstance(IGameObj* GameObj);
	
	void UnRegInstance(IGameObj* GameObj);

	template< class T >
	T* GetInstance(int instanceId)
	{
		auto obj = GetGameObj(instanceId);
		if(obj != nullptr)
			return Cast<T>(obj);
		return nullptr;
	}

	IGameObj* GetGameObj(int instanceId);

private:
	int createInstanceId;

	TMap<int, IGameObj*> instanceMap;
};
