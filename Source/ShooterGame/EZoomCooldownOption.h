#pragma once

#include "CoreMinimal.h"
#include "EZoomCooldownOption.generated.h"

UENUM(BlueprintType)
enum class EZoomCooldownOption : uint8
{
	ApplyCooldownAfterZoom,
	NoCooldown,
	Count
};