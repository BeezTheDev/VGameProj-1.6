#pragma once

#include "CoreMinimal.h"
#include "EZoomTransitionState.generated.h"

UENUM(BlueprintType)
enum class EZoomTransitionState : uint8
{
	Transitioning = 0,
	OnCooldown = 1,
	Completed = 2
};