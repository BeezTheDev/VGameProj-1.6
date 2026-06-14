#pragma once

#include "CoreMinimal.h"
#include "Base/AresBasePrimaryDataAsset.h"
#include "EquippableSkinChromaDataAsset.generated.h"

UCLASS()
class SHOOTERGAME_API UEquippableSkinChromaDataAsset final : public UAresBasePrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> EquippableSkinChroma;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> UIData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TMap<TSoftClassPtr<UClass>, TSoftClassPtr<UClass>> AttachmentOverrides;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> ModelViewerFXC;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> StreamedVideo;
};