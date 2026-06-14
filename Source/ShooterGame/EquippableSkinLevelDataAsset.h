#pragma once

#include "CoreMinimal.h"
#include "Base/AresBasePrimaryDataAsset.h"
#include "EquippableSkinLevelDataAsset.generated.h"

UCLASS()
class SHOOTERGAME_API UEquippableSkinLevelDataAsset final : public UAresBasePrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> SkinAttachment;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> UIData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> ModelViewerFXC;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> StreamedVideo;
};