  // Copyright Epic Games, Inc. All Rights Reserved.

#include "RogCharacter.h"

#include "AbilitySystemComponent.h"
#include "UIExtensionSystem.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "Rog/Ability/RogAbilitySystemComponent.h"
#include "Rog/GameObj/GameObjMgrSubSystem.h"


ARogCharacter::ARogCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	AbilitySystemComponent = CreateDefaultSubobject<URogAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	

	CharacterBagComponent = CreateDefaultSubobject<UCharacterBagComponent>(TEXT("CharacterBagComponent"));
	CharacterEquipComponent = CreateDefaultSubobject<UCharacterEquipComponent>(TEXT("CharacterEquipComponent"));
	

}

void ARogCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

UAbilitySystemComponent* ARogCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ARogCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

}

void ARogCharacter::BeginPlay()
{
	Super::BeginPlay();
	UGameObjMgrSubSystem::RegInstance(GetWorld(),this);
	UE_LOG(LogTemp,Log,TEXT("ARogCharacter::BeginPlay()"));
	

	AbilitySystemComponent->InitAbilityActorInfo(this,this);
	K2_OnASCInit();
}

void ARogCharacter::BeginDestroy()
{
	Super::BeginDestroy();
	UGameObjMgrSubSystem::UnRegInstance(GetWorld(),this);
	
}

void ARogCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	UE_LOG(LogTemp,Log,TEXT("ARogCharacter::PossessedBy()"));
	
}

void ARogCharacter::PreInitializeComponents()
{
	Super::PreInitializeComponents();
	
}

int ARogCharacter::GetInstanceId()
{
	return InstanceId;
}

ARogPlayerState* ARogCharacter::GetRogPlayerState() const
{
	return CastChecked<ARogPlayerState>(GetPlayerState(),ECastCheckedType::NullAllowed);
}

ARogPlayerController* ARogCharacter::GetRogPlayerController() const
{
	return CastChecked<ARogPlayerController>(Controller,ECastCheckedType::NullAllowed);
}

