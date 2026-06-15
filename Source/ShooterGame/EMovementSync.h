#pragma once

#include "CoreMinimal.h"
#include "EMovementSync.generated.h"

UENUM(BlueprintType)
enum class EMovementSync : uint8
{
	None = 0,
	Start = 1,
	Stop = 2,
	StartAndStop = 3,
	Count = 4
};