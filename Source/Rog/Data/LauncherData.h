// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LauncherData.generated.h"


USTRUCT(BlueprintType)
struct ROG_API FLauncherData
{
	GENERATED_BODY()

public:
	int OwnerInstanceId;
	// 所在的曹魏
	int Slot;
};



USTRUCT(BlueprintType)
struct FBulletData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Bullet")
	FLauncherData OwnerLauncherInfo;


	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Bullet")
	float Damage;
};


