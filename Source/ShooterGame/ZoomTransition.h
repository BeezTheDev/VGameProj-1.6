#pragma once

#include "CoreMinimal.h"
#include "ZoomTransitionDescription.h"
#include "EZoomTransitionState.h"
#include "ZoomTransition.generated.h"

USTRUCT(BlueprintType)
struct FZoomTransition
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FZoomTransitionDescription TransitionDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<EZoomTransitionState> TransitionState;
};