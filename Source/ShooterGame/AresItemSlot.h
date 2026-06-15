#pragma once

#include "CoreMinimal.h"
#include "AresItemSlot.generated.h"

UENUM(BlueprintType)
enum class EAresItemSlot : uint8
{
	Primary = 0,
	Secondary = 1,
	Melee = 2,
	GrenadeAbility = 3,
	Ability1 = 4,
	Ability2 = 5,
	Passive = 6,
	Level = 7,
	Invisible = 8,
	Ultimate = 9,
	Unarmed = 10,
	Armor = 11,
	Count = 12,

	Any = 253,
	Invalid = 254
};