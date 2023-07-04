// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rog/Bullet/BulletBase.h"
#include "LauncherBase.generated.h"



UCLASS(Blueprintable)
class ROG_API ALauncherBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALauncherBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable,Category="Launcher")
	virtual ABulletBase* StartShoot();


	UFUNCTION(BlueprintCallable,Category="Launcher")
	virtual void InitLauncherInfo(int playerId, int slot);

public:

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Launcher")
	float Interval;// 发射间隔

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Launcher")
	TSubclassOf<ABulletBase> BulletCls; // 子弹对象

	UPROPERTY(BlueprintReadWrite)
	FLauncherData LauncherInfo; // 发射器信息
private:
	float time;
};
