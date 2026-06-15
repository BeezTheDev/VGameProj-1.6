#pragma once

#include "CoreMinimal.h"
#include "RoundPersistenceBehavior.generated.h"

UENUM(BlueprintType)
enum class RoundPersistenceBehavior : uint8
{
	DoNothing        = 0,
	Destroy       = 1,
	Persist   = 2,
	PersistIfOwnerAlive   = 3
};