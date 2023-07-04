// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "GameFramework/Actor.h"
#include "Rog/Data/LauncherData.h"
#include "BulletBase.generated.h"



UCLASS()
class ROG_API ABulletBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABulletBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void BeginDestroy() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:


public:
	

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Bullet")
	FBulletData BulletInfo;
	
};
