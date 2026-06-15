#pragma once

#include "CoreMinimal.h"
#include "EStateBehaviorOnDeath.generated.h"

UENUM(BlueprintType)
enum class EStateBehaviorOnDeath : uint8
{
	DoNothing = 0,
	GoToState = 1,
	ClearState = 2,
	Count = 3 UMETA(Hidden)
};