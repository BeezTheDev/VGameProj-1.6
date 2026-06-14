#pragma once

#include "CoreMinimal.h"
#include "Base/AresBasePrimaryDataAsset.h"
#include "EquippableCharmLevelDataAsset.generated.h"

UCLASS()
class SHOOTERGAME_API UEquippableCharmLevelDataAsset final : public UAresBasePrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> UIData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> EquippableCharm;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> CharmAttachment;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 CharmLevel;

public:

	void SetCharmAttachment(TSoftClassPtr<UClass> NewCharmAttachment);
	void SetCharmLevel(int32 NewCharmLevel);
	void SetEquippableCharm(TSoftClassPtr<UClass> NewEquippableCharm);
	void SetUIData(TSoftClassPtr<UClass> NewUIData);

	class UEquippableCharmDataAsset* GetEquippableCharm() const;
};