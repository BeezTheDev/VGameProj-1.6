#pragma once

#include "CoreMinimal.h"
#include "EffectID.generated.h"

USTRUCT(BlueprintType)
struct FEffectID
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	FName SourceID;

	UPROPERTY(BlueprintReadOnly)
	int64 EffectID;

	UPROPERTY(BlueprintReadOnly)
	bool bLocalEffect;

	UPROPERTY(BlueprintReadOnly)
	bool bTransient;
};