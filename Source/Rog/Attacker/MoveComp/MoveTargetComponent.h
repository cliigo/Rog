// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoveTargetComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ROG_API UMoveTargetComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMoveTargetComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
								FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Move")
	float MoveSpeed;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Move")
	float StartMoveSpeed;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	FVector TargetPos;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	TObjectPtr<UCurveFloat> StartMoveCurve;

private:
	FVector mStartPos;
	float mTime;
	float mCurveMaxTime;
};
