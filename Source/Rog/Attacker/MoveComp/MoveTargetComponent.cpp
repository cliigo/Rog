// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveTargetComponent.h"


// Sets default values for this component's properties
UMoveTargetComponent::UMoveTargetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoveTargetComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	mTime = 0;
	mStartPos = GetOwner()->GetActorLocation();
	float min;
	StartMoveCurve->GetTimeRange(min,mCurveMaxTime);
}


// Called every frame
void UMoveTargetComponent::TickComponent(float DeltaTime, ELevelTick TickType,
										FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	auto owner = GetOwner();
	if(!IsValid(owner))
		return;
	mTime += DeltaTime;
	const auto curPos = owner->GetActorLocation();
	auto nextPos = curPos;
	
	nextPos += (TargetPos - curPos).GetSafeNormal() * MoveSpeed * DeltaTime ;
	if(mTime <= mCurveMaxTime)
	{
		const float value = StartMoveCurve->FloatCurve.Eval(mTime) * StartMoveSpeed;
		nextPos.Z += value;
	}
	const auto dir=  nextPos - curPos;
	if(dir.SquaredLength() > 1.0f)
	{
		owner->SetActorRotation(dir.GetSafeNormal().Rotation());
		owner->SetActorLocation(nextPos);	
	}
	
	
}

