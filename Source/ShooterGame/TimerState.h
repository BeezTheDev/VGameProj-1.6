#pragma once

#include "CoreMinimal.h"
#include "TimerState.generated.h"

USTRUCT(BlueprintType)
struct FTimerState
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	bool bPaused;
};