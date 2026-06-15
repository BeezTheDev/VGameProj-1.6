#pragma once

#include "CoreMinimal.h"
#include "EmbeddedEffectInfo.h"
#include "EStateContext.h"
#include "EMovementSync.h"
#include "ScriptStateEffectInfo.generated.h"

USTRUCT(BlueprintType)
struct FScriptStateEffectInfo
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FEmbeddedEffectInfo Effect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bStopEffectOnStateEnd = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bOwnerEffectOnly = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EStateContext Context;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMovementSync MovementSync;
};