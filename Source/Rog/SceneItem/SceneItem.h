// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rog/Data/Item/ItemData.h"
#include "SceneItem.generated.h"

UCLASS()
class ROG_API ASceneItem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASceneItem();

public:

	UPROPERTY(BlueprintReadWrite)
	FItemData ItemData;
	
};
