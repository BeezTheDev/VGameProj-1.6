#pragma once

#include "CoreMinimal.h"
#include "EmbeddedEffectInfo.generated.h"

class AEffectContainer;

USTRUCT(BlueprintType)
struct FEmbeddedEffectInfo
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AEffectContainer> EffectType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FVector AttachOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FRotator AttachRotation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName AttachSocket;
};