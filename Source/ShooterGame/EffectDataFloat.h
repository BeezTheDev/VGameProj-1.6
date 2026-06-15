#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EffectDataFloat.generated.h"

USTRUCT(BlueprintType)
struct FEffectDataFloat
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value = 0.0f;
};