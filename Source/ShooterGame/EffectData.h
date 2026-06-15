#pragma once

#include "CoreMinimal.h"
#include "EffectDataFloat.h"
#include "EffectDataVector.h"
#include "EffectDataObject.h"
#include "EffectDataClass.h"
#include "EffectData.generated.h"

USTRUCT(BlueprintType)
struct FEffectData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	TWeakObjectPtr<AActor> WaitOnReplicationActor;

protected:

	UPROPERTY()
	TArray<FEffectDataFloat> FloatValues;

	UPROPERTY()
	TArray<FEffectDataVector> VectorValues;

	UPROPERTY()
	TArray<FEffectDataObject> ObjectValues;

	UPROPERTY()
	TArray<FEffectDataClass> ClassValues;
};