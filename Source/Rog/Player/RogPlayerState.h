// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "ModularPlayerState.h"
#include "GameFramework/PlayerState.h"
#include "UObject/Object.h"
#include "RogPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class ROG_API ARogPlayerState : public AModularPlayerState
{
	GENERATED_BODY()

public:
	ARogPlayerState(const FObjectInitializer& ObjectInitializer) ;

	
	
};
