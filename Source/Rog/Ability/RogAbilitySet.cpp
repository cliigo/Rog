// Fill out your copyright notice in the Description page of Project Settings.


#include "RogAbilitySet.h"

void FRogAbilitySet_GrantedHandles::AddAbilitySpecHandle(const FGameplayAbilitySpecHandle& AbilitySpecHandle)
{
	if(AbilitySpecHandle.IsValid())
	{
		AbilitySpecHandles.Add(AbilitySpecHandle);
	}
}

void FRogAbilitySet_GrantedHandles::AddEffectSpecHandle(const FActiveGameplayEffectHandle& EffectSpecHandle)
{
	if(EffectSpecHandle.IsValid())
	{
		EffectSpecHandles.Add(EffectSpecHandle);
	}
}

void FRogAbilitySet_GrantedHandles::AddAttributeSet(UAttributeSet* AttributeSet)
{
	if(AttributeSet)
	{
		AttributeSets.Add(AttributeSet);
	}
}

void FRogAbilitySet_GrantedHandles::TaskFormAbilitySystem(URogAbilitySystemComponent* RogASC)
{
	check(RogASC);
	if (!RogASC->IsOwnerActorAuthoritative())
    {
    	// Must be authoritative to give or take ability sets.
    	return;
    }
    for (const FGameplayAbilitySpecHandle& Handle : AbilitySpecHandles)
    {
		if (Handle.IsValid())
		{
			RogASC->ClearAbility(Handle);
		}
	}
	
	for (const FActiveGameplayEffectHandle& Handle : EffectSpecHandles)
	{
		if (Handle.IsValid())
		{
			RogASC->RemoveActiveGameplayEffect(Handle);
		}
	}
	
	for (UAttributeSet* Set : AttributeSets)
	{
		RogASC->RemoveSpawnedAttribute(Set);
	}
	
	AbilitySpecHandles.Reset();
	EffectSpecHandles.Reset();
	AttributeSets.Reset();
}

void FRogAbilitySet::GiveToAbilitySystem(URogAbilitySystemComponent* RogASC,FRogAbilitySet_GrantedHandles* OutGrantedHandles, UObject*SourceObject) const
{
	check(RogASC);
	if (!RogASC->IsOwnerActorAuthoritative())
	{
		// Must be authoritative to give or take ability sets.
		return;
	}
	for(int abilityIndex = 0; abilityIndex < GrantedGameplayAbilities.Num(); abilityIndex++)
	{
		const auto& AbilityToGrant = GrantedGameplayAbilities[abilityIndex];
		if(!IsValid(AbilityToGrant.Ability))
		{
			continue;
		}
		URogGameplayAbility* AbilityCDO = AbilityToGrant.Ability->GetDefaultObject<URogGameplayAbility>();
		FGameplayAbilitySpec AbilitySpec(AbilityCDO, AbilityToGrant.AbilityLevel);
		AbilitySpec.SourceObject = SourceObject;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilityToGrant.InputTag);

		FGameplayAbilitySpecHandle AbilitySpecHandle;
		if(AbilityToGrant.IsActive)
		{
			AbilitySpecHandle = RogASC->GiveAbilityAndActivateOnce(AbilitySpec);
		}
		else
		{
			AbilitySpecHandle = RogASC->GiveAbility(AbilitySpec);	
		}
		
		if(OutGrantedHandles)
		{
			OutGrantedHandles->AddAbilitySpecHandle(AbilitySpecHandle);
		}
		
	}
	for(int effectIndex = 0; effectIndex < GrantedGameplayEffects.Num(); effectIndex++)
	{
		const auto& EffectToGrant = GrantedGameplayEffects[effectIndex];
		if(!IsValid(EffectToGrant.GameplayEffect))
		{
			continue;
		}
		UGameplayEffect* GameplayEffect = EffectToGrant.GameplayEffect->GetDefaultObject<UGameplayEffect>();
		const FActiveGameplayEffectHandle EffectSpecHandle = RogASC->ApplyGameplayEffectToSelf(GameplayEffect, EffectToGrant.EffectLevel, RogASC->MakeEffectContext());
		if(OutGrantedHandles)
		{
			OutGrantedHandles->AddEffectSpecHandle(EffectSpecHandle);
		}
	}

	for(int setIndex = 0; setIndex < GrantedAttributeSets.Num(); ++ setIndex)
	{
		const FRogAbilitySet_AttributeSet& SetToGrant = GrantedAttributeSets[setIndex];
		if(!IsValid(SetToGrant.AttributeSet))
		{
			continue;
		}
		UAttributeSet* AttributeSet = NewObject<UAttributeSet>(RogASC->GetOwner(), SetToGrant.AttributeSet);
		RogASC->AddSpawnedAttribute(AttributeSet);
		if(OutGrantedHandles)
		{
			OutGrantedHandles->AddAttributeSet(AttributeSet);
		}
		
	}
	
}
