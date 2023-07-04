// Copyright Epic Games, Inc. All Rights Reserved.

#include "RogPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

ARogPlayerController::ARogPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CachedDestination = FVector::ZeroVector;
	FollowTime = 0.f;
}

void ARogPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered, this, & ARogPlayerController::OnMove);
		EnhancedInputComponent->BindAction(LookAtAction,ETriggerEvent::Triggered,this, & ARogPlayerController::OnLookAt);
	}
}

void ARogPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	Subsystem->AddMappingContext(InputConfig,0);
}

void ARogPlayerController::OnMove(const FInputActionValue& Value)
{
	const FVector2D moveDir =Value.Get<FVector2D>();

	auto pawn = GetPawn();
	if(pawn != nullptr)
	{
		const auto rot = GetControlRotation();
		const auto move = rot.RotateVector(FVector(moveDir.X, moveDir.Y, 0)) ;
		pawn->AddMovementInput(move,1.0f, false);
	}
	
}

void ARogPlayerController::OnLookAt(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector =Value.Get<FVector2D>();

	// 往屏幕输出位置
	 UE_LOG(LogTemp, Warning, TEXT("LookAxisVector.X: %f Y:%f"), LookAxisVector.X,LookAxisVector.Y);
	
	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
}

