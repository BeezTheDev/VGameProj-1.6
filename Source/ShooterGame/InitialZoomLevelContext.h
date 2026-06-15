#pragma once

#include "CoreMinimal.h"
#include "StateTransitionContext.h"
#include "InitialZoomLevelContext.generated.h"

UCLASS()
class SHOOTERGAME_API UInitialZoomLevelContext final : public UStateTransitionContext
{
	GENERATED_BODY()

public:

	UPROPERTY()
	int32 ZoomLevel = 0;

public:

	void SetZoomLevel(int32 InitialZoomLevel);
};