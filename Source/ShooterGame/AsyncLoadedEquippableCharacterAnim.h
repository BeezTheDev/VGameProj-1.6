#pragma once

#include "CoreMinimal.h"
#include "Engine/StreamableManager.h"
#include "AsyncLoadedEquippableCharacterAnim.generated.h"

class UAnimationAsset;

USTRUCT()
struct FAsyncLoadedEquippableCharacterAnim
{
	GENERATED_BODY()

public:

	TSharedPtr<FStreamableHandle> AltModeStreamingHandle;

	UPROPERTY()
	UAnimationAsset* LoadedAltModeAsset;

	TSharedPtr<FStreamableHandle> DefaultStreamingHandle;

	UPROPERTY()
	UAnimationAsset* LoadedDefaultAsset;
};