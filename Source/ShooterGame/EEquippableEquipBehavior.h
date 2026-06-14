#pragma once

#include "CoreMinimal.h"
#include "EEquippableEquipBehavior.generated.h"

UENUM(BlueprintType)
enum class EEquippableEquipBehavior : uint8
{
	RequireResources = 0,
	AlwaysEquip = 1,
	NeverEquip = 2,
	Count = 3
};