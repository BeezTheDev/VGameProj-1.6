#pragma once

#include "CoreMinimal.h"
#include "EStateContext.generated.h"

UENUM(BlueprintType)
enum class EStateContext : uint8
{
	None = 0,
	TriggeringState = 1,
	OwningEquippable = 2,
	OwningCharacter = 3,
	CustomContext = 4,
	Count = 5
};