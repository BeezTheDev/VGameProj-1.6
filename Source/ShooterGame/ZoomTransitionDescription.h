#pragma once

#include "CoreMinimal.h"
#include "EZoomCooldownOption.h"
#include "ZoomTransitionDescription.generated.h"

USTRUCT(BlueprintType)
struct FZoomTransitionDescription
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SourceFov = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SourceFov1P = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SourceZoomLevel = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TargetFov = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TargetFov1P = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 TargetZoomLevel = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TotalTransitionTimeDuration = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EZoomCooldownOption CooldownOption;
};