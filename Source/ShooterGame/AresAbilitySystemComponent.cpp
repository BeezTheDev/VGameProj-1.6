#include "AresAbilitySystemComponent.h"

void UAresAbilitySystemComponent::AddAttributeChangeEvent(const FGameplayAttribute& Attribute, const FAttributeValueChangedDelegate& Event)
{
}

void UAresAbilitySystemComponent::EffectRemoved(const FActiveGameplayEffect& ActiveEffect)
{
}

float UAresAbilitySystemComponent::GetTimeSinceTrackedAttributeChanged(const FGameplayAttribute& Attribute)
{
	return 0.0f;
}

void UAresAbilitySystemComponent::RemoveAllActiveEffects()
{
}

void UAresAbilitySystemComponent::RemoveAttributeChangeEvent(const FGameplayAttribute& Attribute, const FAttributeValueChangedDelegate& Event)
{
}

bool UAresAbilitySystemComponent::GetBoolAttribute(const FGameplayAttribute& Attribute) const
{
	return false;
}

float UAresAbilitySystemComponent::GetFloatAttribute(const FGameplayAttribute& Attribute) const
{
	return 0.0f;
}

AActor* UAresAbilitySystemComponent::GetGameplayEffectCauser(const FActiveGameplayEffectHandle& Handle) const
{
	return nullptr;
}

AActor* UAresAbilitySystemComponent::GetGameplayEffectInstigator(const FActiveGameplayEffectHandle& Handle) const
{
	return nullptr;
}

TArray<FActiveGameplayEffectHandle> UAresAbilitySystemComponent::GetGameplayEffectsByCauser(TSubclassOf<UGameplayEffect> EffectType, AActor* Causer) const
{
	return TArray<FActiveGameplayEffectHandle>();
}

TArray<FActiveGameplayEffectHandle> UAresAbilitySystemComponent::GetGameplayEffectsByInstigator(TSubclassOf<UGameplayEffect> EffectType, AActor* Instigator) const
{
	return TArray<FActiveGameplayEffectHandle>();
}