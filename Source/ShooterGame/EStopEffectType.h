#pragma once

#include "CoreMinimal.h"
#include "EStopEffectType.generated.h"

UENUM(BlueprintType)
enum class EStopEffectType : uint8
{
	Normal = 0,
	ForceKill = 1
};