// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "CharacterBagComponent.h"
#include "CharacterEquipComponent.h"
#include "ModularCharacter.h"
#include "Rog/GameObj/GameObj.h"
#include "Rog/Player/RogPlayerController.h"
#include "Rog/Player/RogPlayerState.h"
#include "RogCharacter.generated.h"

UCLASS(Blueprintable)
class ARogCharacter : public AModularCharacter, public IAbilitySystemInterface, public IGameObj
{
	GENERATED_BODY()

public:
	ARogCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;


	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void OnRep_PlayerState() override;
	virtual void BeginPlay() override;

	virtual void BeginDestroy() override;

	virtual void PossessedBy(AController * NewController) override;
	
	virtual void PreInitializeComponents() override;

	UFUNCTION(BlueprintCallable)
	virtual int GetInstanceId() override;

	UFUNCTION(BlueprintCallable)
	ARogPlayerState* GetRogPlayerState() const;

	UFUNCTION(BlueprintCallable)
	ARogPlayerController* GetRogPlayerController() const;

	UFUNCTION(BlueprintImplementableEvent,Category="Ability",DisplayName="OnAscInit")
	void K2_OnASCInit();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Equip")
	TObjectPtr<UCharacterEquipComponent> CharacterEquipComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Bag")
	TObjectPtr<UCharacterBagComponent> CharacterBagComponent;

	

	
};

