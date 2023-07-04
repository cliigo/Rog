// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Rog/Data/LauncherData.h"
#include "UObject/Object.h"
#include "DamageWorldSystem.generated.h"



/**
 *  伤害计算系统
 */
UCLASS(Blueprintable,BlueprintType)
class ROG_API UDamageWorldSystem : public UWorldSubsystem
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable, Category = "Damage")
	void DoDamage(int attackerId, int targetId, const FBulletData& BulletInfo);

	
};
