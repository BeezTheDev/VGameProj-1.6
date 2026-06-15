#pragma once

#include "CoreMinimal.h"
#include "EEquippableTickState.generated.h"

UENUM(BlueprintType)
enum class EEquippableTickState : uint8
{
	TickFromActorTickGraph = 0,
	TickFromInventory = 1,
	Disabled = 2,
	Count = 3
};