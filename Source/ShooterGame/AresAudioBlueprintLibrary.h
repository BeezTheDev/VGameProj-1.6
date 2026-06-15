#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AresAudioBlueprintLibrary.generated.h"

class UAkAudioEvent;
class UAkAudioBank;
class UObject;
class AAresActorSoundPool;
class AAresSoundHandler;

UCLASS()
class SHOOTERGAME_API UAresAudioBlueprintLibrary final : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
};