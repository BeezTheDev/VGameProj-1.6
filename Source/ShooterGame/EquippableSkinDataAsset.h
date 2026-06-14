#pragma once

#include "CoreMinimal.h"
#include "Base/AresBasePrimaryDataAsset.h"
#include "EquippableSkinDataAsset.generated.h"

UCLASS()
class SHOOTERGAME_API UEquippableSkinDataAsset final : public UAresBasePrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> Equippable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<TSoftClassPtr<UClass>> Levels;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> DefaultChroma;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<TSoftClassPtr<UClass>> Chromas;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> UIData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TMap<TSoftClassPtr<UClass>, TSoftClassPtr<UClass>> AttachmentOverrides;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> Theme;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> ContentTier;

public:

	class UEquippableSkinLevelDataAsset* GetSkinLevel(int32 LevelNumber) const;
};