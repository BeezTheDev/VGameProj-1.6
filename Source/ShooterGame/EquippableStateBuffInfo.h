#pragma once

#include "CoreMinimal.h"
#include "AresGameplayBuff.h"
#include "EquippableStateBuffInfo.generated.h"

class UAresGameplayBuff;
class UAresAbilitySystemComponent;

USTRUCT(BlueprintType)
struct FEquippableStateBuffInfo
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UAresGameplayBuff> BuffClass;

	UPROPERTY(EditDefaultsOnly)
	float BuffLevel;

	UPROPERTY(Transient)
	UAresAbilitySystemComponent* BuffTarget;
};