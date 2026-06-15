#pragma once

#include "CoreMinimal.h"
#include "EEffectAttachType.generated.h"

UENUM(BlueprintType)
enum class EEffectAttachType : uint8
{
	NotAttached = 0,
	RootComponent = 1,
	Attach1P = 2,
	Attach3P = 3,
	Count = 4 UMETA(Hidden)
};