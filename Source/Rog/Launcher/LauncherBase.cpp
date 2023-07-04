// Fill out your copyright notice in the Description page of Project Settings.


#include "LauncherBase.h"

#include "Rog/Bullet/BulletBase.h"


// Sets default values
ALauncherBase::ALauncherBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALauncherBase::BeginPlay()
{
	Super::BeginPlay();
	time = Interval;
	
}

// Called every frame
void ALauncherBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	time -= DeltaTime;
	if(time <= 0)
	{
		// 开始发射
		StartShoot();	
	}
	time += Interval;
}

ABulletBase* ALauncherBase::StartShoot()
{
	const auto bullet = this->GetWorld()->SpawnActor<ABulletBase>(BulletCls);
	bullet->SetActorLocation(GetActorLocation());
	bullet->SetActorRotation(GetActorRotation());
	return bullet;
	
}

void ALauncherBase::InitLauncherInfo(int playerId, int slot)
{
	LauncherInfo.OwnerInstanceId = playerId;
	LauncherInfo.Slot = slot;
}

