#pragma once

#include "CoreMinimal.h"
#include "EMovementSyncType.generated.h"

UENUM(BlueprintType)
enum class EMovementSyncType : uint8
{
	Always = 0,
	Never = 1,
	SpectatorOnly = 2,
	Count = 3 UMETA(Hidden)
};