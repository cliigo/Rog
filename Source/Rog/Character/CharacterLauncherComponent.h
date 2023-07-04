// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Rog/Launcher/LauncherBase.h"
#include "CharacterLauncherComponent.generated.h"


// 发射器组件
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ROG_API UCharacterLauncherComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCharacterLauncherComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	
	void InitSlot(int maxCount);


public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
								FActorComponentTickFunction* ThisTickFunction) override;


	UFUNCTION(BlueprintCallable)
	void UpdateSlotPos(int slot, FVector pos);


	UFUNCTION(BlueprintCallable)
	bool AddLauncher(int slot,ALauncherBase* launcher);

	UFUNCTION(BlueprintCallable)
	ALauncherBase* RmLauncher(int slot);


public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Launcher")
	int MaxSlotCount; // 最大的槽位

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Launcher")
	float SlotRange;// 槽位生成范围

private:
	TMap<int, TObjectPtr<ALauncherBase>> SlotToLauncherMap;
	TMap<int, FVector> SlotToOffset;
	
	
	
	
};
