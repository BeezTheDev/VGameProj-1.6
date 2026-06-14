#pragma once

#include "CoreMinimal.h"
#include "Base/AresBasePrimaryDataAsset.h"
#include "EquippableDataAsset.generated.h"

UCLASS()
class SHOOTERGAME_API UEquippableDataAsset final : public UAresBasePrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> Equippable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> UIData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 MaxAttachmentCost;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSet<TSoftClassPtr<UClass>> ForcedAttachments;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> DefaultSkin;
};