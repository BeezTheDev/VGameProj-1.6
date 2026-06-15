#pragma once

#include "CoreMinimal.h"
#include "ZoomTransitionSettings.generated.h"

USTRUCT(BlueprintType)
struct FZoomTransitionSettings
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ZoomInInitialTimeDuration = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float CosmeticZoomInTriggerPercent = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ZoomInSuccessiveTimeDuration = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ZoomOutTimeDuration = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ZoomCooldownTimeDuration = 0.0f;
};