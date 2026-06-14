#pragma once

#include "CoreMinimal.h"
#include "EAresDropOnDeath.generated.h"

UENUM(BlueprintType)
enum class EAresDropOnDeath : uint8
{
	Never = 0,
	IfNoPrimary = 1,
	Always = 2,
	Count = 3,
	Invalid = 254
};