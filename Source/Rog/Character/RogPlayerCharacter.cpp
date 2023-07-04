// Fill out your copyright notice in the Description page of Project Settings.


#include "RogPlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Called when the game starts or when spawned
void ARogPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARogPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ARogPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

