#pragma once

#include "CoreMinimal.h"
#include "EZoomOutShowOption.generated.h"

UENUM(BlueprintType)
enum class EZoomOutShowOption : uint8
{
	OnUnZoomStarted = 0,
	WhenFullyZoomedOut = 1,
	Count = 2
};