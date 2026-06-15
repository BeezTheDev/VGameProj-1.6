#pragma once

#include "CoreMinimal.h"
#include "EffectData.h"
#include "EMovementSync.h"
#include "EffectManagerComponent.h"
#include "ActiveScriptStateEffect.generated.h"

class UEffectManagerComponent;

USTRUCT(BlueprintType)
struct FActiveScriptStateEffect
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FEffectData EffectID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMovementSync MovementSync;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UEffectManagerComponent* TargetEffectManager;
};