// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterLauncherComponent.h"

#include "RogCharacter.h"


// Sets default values for this component's properties
UCharacterLauncherComponent::UCharacterLauncherComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCharacterLauncherComponent::BeginPlay()
{
	Super::BeginPlay();

	InitSlot(MaxSlotCount);

	
}

void UCharacterLauncherComponent::InitSlot(int maxCount)
{
	MaxSlotCount = maxCount;
	// 生成均匀分布在圆上的角度
	const float AngleIncrement = 360.0f / static_cast <float>(MaxSlotCount);

	
	for(int i = 0; i < maxCount; i ++)
	{
		SlotToLauncherMap.Add(i, nullptr);

		const float Angle = AngleIncrement * i;

		// 将角度转换为弧度
		const float Radians = FMath::DegreesToRadians(Angle);

		// 计算点的位置
		const float X =  SlotRange * FMath::Cos(Radians);
		const float Z = SlotRange * FMath::Sin(Radians);
		SlotToOffset.Add(i,FVector(X,0,Z));
	}	
}



// Called every frame
void UCharacterLauncherComponent::TickComponent(float DeltaTime, ELevelTick TickType,
												FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	// auto curPos = GetOwner()->GetActorLocation();
	// auto rot = GetOwner()->GetActorRotation();
	//
	// for(int i  = 0 ; i< MaxSlotCount; i++)
	// {
	// 	auto offset = SlotToOffset[i];
	// 	auto launcher = SlotToLauncherMap[i];
	// 	if(IsValid(launcher))
	// 	{
	// 		launcher->SetActorLocation(curPos + offset);
	// 		launcher->SetActorRotation(rot);
	// 	}
	// }
	
}

void UCharacterLauncherComponent::UpdateSlotPos(int slot, FVector pos)
{
	SlotToOffset[slot] = pos;
}

bool UCharacterLauncherComponent::AddLauncher(int slot,ALauncherBase* launcher)
{
	if(!IsValid(launcher))
		return false;
	const auto old = SlotToLauncherMap[slot];
	if(IsValid(old))
		return false;
	
	const auto character = Cast<ARogCharacter>(GetOwner() );
	if(!IsValid(character))
		return false;
	
	launcher->InitLauncherInfo(character->GetInstanceId(),slot);
	SlotToLauncherMap[slot] = launcher;
	// 初始化位置
	launcher->SetActorRotation(character->GetActorRotation());
	launcher->SetActorLocation(character->GetActorLocation() + SlotToOffset[slot]);
	// attach 到actor上
	launcher->AttachToActor(GetOwner(),FAttachmentTransformRules::KeepRelativeTransform);
	return true;
}

 ALauncherBase* UCharacterLauncherComponent::RmLauncher(int slot)
{
	auto ptr = SlotToLauncherMap.Find(slot);
	if(ptr != nullptr)
	{

		auto target = ptr->Get();
		target->DetachFromActor(FDetachmentTransformRules::KeepRelativeTransform);
		SlotToLauncherMap[slot] = nullptr;
		return target;
		
	}
	return nullptr;
	
}


