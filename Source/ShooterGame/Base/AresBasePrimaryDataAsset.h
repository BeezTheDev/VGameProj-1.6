#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Misc/Guid.h"
#include "AresBasePrimaryDataAsset.generated.h"

UCLASS(Abstract)
class SHOOTERGAME_API UAresBasePrimaryDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGuid Uuid;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bHideIfNotOwned;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bBaseContent;
};