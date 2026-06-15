#pragma once

#include "CoreMinimal.h"
#include "EEquippableInInventory.generated.h"

UENUM(BlueprintType)
enum class EEquippableInInventory : uint8
{
	No = 0,
	Yes = 1,
};