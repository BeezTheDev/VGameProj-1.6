#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EffectDataVector.generated.h"

USTRUCT(BlueprintType)
struct FEffectDataVector
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Value = FVector::ZeroVector;
};