#pragma once

#include "CoreMinimal.h"
#include "EEquippableRejectInputReason.generated.h"

UENUM(BlueprintType)
enum class EEquippableRejectInputReason : uint8
{
	NoResources = 0,
	OutsideGameplay = 1,
	OnCooldown = 2,
	BlockedByCurrentEquippable = 3,
	EquipSlotDisabled = 4
};