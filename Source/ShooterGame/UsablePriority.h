#pragma once

#include "CoreMinimal.h"
#include "UsablePriority.generated.h"

UENUM(BlueprintType)
enum class EUsablePriority : uint8
{
	Cosmetic    = 0,
	Door        = 1,
	ItemPickup  = 2,
	Default     = 3,
	High        = 4,
	Critical    = 5,
};