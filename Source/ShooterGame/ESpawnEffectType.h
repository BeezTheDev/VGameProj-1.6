#pragma once

#include "CoreMinimal.h"
#include "ESpawnEffectType.generated.h"

UENUM(BlueprintType)
enum class ESpawnEffectType : uint8
{
	Spawned = 0,
	Pooled = 1,
	Pure = 2
};