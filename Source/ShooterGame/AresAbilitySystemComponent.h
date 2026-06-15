#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AresAttributeSet.h"
#include "AttributeSet.h"
#include "AttributeValueChangeDelegateList.h"
#include "AresAbilitySystemComponent.generated.h"

class UAresAttributeSet;
class UGameplayEffect;

UCLASS()
class SHOOTERGAME_API UAresAbilitySystemComponent final : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TArray<FGameplayAttribute> TrackedAttributes;

private:

	UPROPERTY(Transient)
	TMap<FGameplayAttribute, float> AttributeChangedTimeMap;

	UPROPERTY(Transient)
	TMap<FGameplayAttribute, FAttributeValueChangeDelegateList> AttributeChangedEvents;

	UPROPERTY()
	UAresAttributeSet* CachedAttributeSet;

public:

	void AddAttributeChangeEvent(const FGameplayAttribute& Attribute, const FAttributeValueChangedDelegate& Event);
	void EffectRemoved(const FActiveGameplayEffect& ActiveEffect);
	float GetTimeSinceTrackedAttributeChanged(const FGameplayAttribute& Attribute);
	void RemoveAllActiveEffects();
	void RemoveAttributeChangeEvent(const FGameplayAttribute& Attribute, const FAttributeValueChangedDelegate& Event);

	bool GetBoolAttribute(const FGameplayAttribute& Attribute) const;
	float GetFloatAttribute(const FGameplayAttribute& Attribute) const;
	AActor* GetGameplayEffectCauser(const FActiveGameplayEffectHandle& Handle) const;
	AActor* GetGameplayEffectInstigator(const FActiveGameplayEffectHandle& Handle) const;
	TArray<FActiveGameplayEffectHandle> GetGameplayEffectsByCauser(TSubclassOf<UGameplayEffect> EffectType, AActor* Causer) const;
	TArray<FActiveGameplayEffectHandle> GetGameplayEffectsByInstigator(TSubclassOf<UGameplayEffect> EffectType, AActor* Instigator) const;
};