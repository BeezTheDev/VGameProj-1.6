#pragma once

#include "CoreMinimal.h"
#include "EZoomInHideOption.generated.h"

UENUM(BlueprintType)
enum class EZoomInHideOption : uint8
{
	LeaveVisible = 0,
	OnZoomInStarted = 1,
	WhenFullyZoomedIn = 2,
	Count = 3
};