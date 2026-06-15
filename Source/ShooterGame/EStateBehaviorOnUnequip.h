#pragma once

#include "CoreMinimal.h"
#include "EStateBehaviorOnUnequip.generated.h"

UENUM(BlueprintType)
enum class EStateBehaviorOnUnequip : uint8
{
	Normal = 0,
	GoToStartState = 1,
	PreventUnequip = 2,
	PreventEquip = 3,
	Count = 4
};