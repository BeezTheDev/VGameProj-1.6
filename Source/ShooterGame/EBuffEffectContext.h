#pragma once

#include "CoreMinimal.h"
#include "EBuffEffectContext.generated.h"

UENUM(BlueprintType)
enum class EBuffEffectContext : uint8
{
	Instigator = 0,
	Causer   = 1,
	BuffEffectContext_Count   = 2
};