#pragma once

#include "CoreMinimal.h"
#include "Base/AresBasePrimaryDataAsset.h"
#include "EquippableCharmDataAsset.generated.h"

UCLASS()
class SHOOTERGAME_API UEquippableCharmDataAsset final : public UAresBasePrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> UIData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<TSoftClassPtr<UClass>> Levels;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<UClass> Theme;
};