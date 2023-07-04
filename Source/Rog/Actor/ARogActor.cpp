// Fill out your copyright notice in the Description page of Project Settings.


#include "ARogActor.h"


// Sets default values
AARogActor::AARogActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AARogActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AARogActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

