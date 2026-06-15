#pragma once

#include "CoreMinimal.h"
#include "EffectID.h"
#include "EffectContainer.h"
#include "PendingReplicationEffect.generated.h"

USTRUCT()
struct FPendingReplicationEffect
{
	GENERATED_BODY()

public:

	UPROPERTY()
	FEffectID EffectID;

	UPROPERTY()
	TSubclassOf<class AEffectContainer> EffectType;
};