#pragma once

#include "CoreMinimal.h"
#include "Engine/StreamableManager.h"
#include "AsyncLoadedEquippableGunAnim.generated.h"

class UAnimationAsset;

USTRUCT()
struct FAsyncLoadedEquippableGunAnim
{
	GENERATED_BODY()

public:

	TSharedPtr<FStreamableHandle> DefaultStreamingHandle;

	UPROPERTY()
	UAnimationAsset* LoadedDefaultAsset;

	TSharedPtr<FStreamableHandle> CosmeticStreamingHandle;

	UPROPERTY()
	UAnimationAsset* LoadedCosmeticAsset;

	TSharedPtr<FStreamableHandle> CosmeticAltModeStreamingHandle;

	UPROPERTY()
	UAnimationAsset* LoadedCosmeticAltModeAsset;
};