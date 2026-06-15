#pragma once

#include "CoreMinimal.h"
#include "EAresEquippableInputAction.generated.h"

UENUM(BlueprintType)
enum class EAresEquippableInputAction : uint8
{
	EquippableInputAction_WentDown = 0,
	EquippableInputAction_IsDown   = 1,
	EquippableInputAction_WentUp   = 2,
	EquippableInputAction_IsUp     = 3,
	EquippableInputAction_Count    = 4,
};