#pragma once

#include "CoreMinimal.h"
#include "ZoomLevelInfo.generated.h"

USTRUCT(BlueprintType)
struct FZoomLevelInfo
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Multiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bUseDefaultFov1P = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Fov1P = 90.0f;
};