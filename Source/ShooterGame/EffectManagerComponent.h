#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PendingReplicationEffect.h"
#include "EffectManagerComponent.generated.h"

class AEffectContainer;
class APlayerController;
class AActor;
class AAresPlayerController;

enum class EAresAlliance : uint8;
enum class EStopEffectType : uint8;
enum class EFoWRelevancyResult : uint8;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SHOOTERGAME_API UEffectManagerComponent : public UActorComponent
{
    GENERATED_BODY()

public:

    bool bDeferActiveEffects;
    
    TArray<FPendingReplicationEffect> EffectsPendingReplication;

public:

    void ClearExpiredTimer(const FEffectID& EffectID);

    void ClientPlayContinuousEffect(
        TSubclassOf<AEffectContainer> EffectContainer,
        const FEffectData& EffectData,
        const FTransform& Transform,
        FName AttachSocket,
        const FEffectID& EffectID,
        APlayerController* ClientControllerThatTriggered,
        float StartMovementTime,
        EAresAlliance AllianceFilter);

    void ClientPlayOneShotEffect(
        TSubclassOf<AEffectContainer> EffectContainer,
        const FEffectData& EffectData,
        const FTransform& Transform,
        FName AttachSocket,
        APlayerController* ClientControllerThatTriggered,
        float StartMovementTime,
        EAresAlliance AllianceFilter);

    void ClientStopContinuousEffect(
        const FEffectID& EffectID,
        APlayerController* ClientControllerThatTriggered,
        EStopEffectType StopEffectType,
        float StopMovementTime);

    void ClientUpdateContinuousEffect(
        const FEffectID& EffectID,
        const FEffectData& EffectData,
        APlayerController* ClientControllerThatTriggered);

    void OnBecomeRelevant(AActor* OwningActor);

    void OnServerLeaveFoW(
        AActor* OwningActor,
        const AAresPlayerController* Viewer,
        EFoWRelevancyResult Relevance,
        EFoWRelevancyResult OldRelevance);

    void OnStopBeingRelevant(AActor* OwningActor);

    void PostMovementUpdate(float Timestamp);

    void PreMovementUpdate(float Timestamp);

    void StartDeferredEffects();

    void StopContinuousEffect(
        const FEffectID& EffectID,
        EStopEffectType StopEffectType);

    void StopContinuousEffectsOfType(
        TSubclassOf<AEffectContainer> EffectContainer,
        EStopEffectType StopEffectType);
};