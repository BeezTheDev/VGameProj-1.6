#include "EffectManagerComponent.h"

void UEffectManagerComponent::ClearExpiredTimer(const FEffectID& EffectID)
{
    return;
}

void UEffectManagerComponent::ClientPlayContinuousEffect(
    TSubclassOf<AEffectContainer> EffectContainer,
    const FEffectData& EffectData,
    const FTransform& Transform,
    FName AttachSocket,
    const FEffectID& EffectID,
    APlayerController* ClientControllerThatTriggered,
    float StartMovementTime,
    EAresAlliance AllianceFilter)
{
    return;
}

void UEffectManagerComponent::ClientPlayOneShotEffect(
    TSubclassOf<AEffectContainer> EffectContainer,
    const FEffectData& EffectData,
    const FTransform& Transform,
    FName AttachSocket,
    APlayerController* ClientControllerThatTriggered,
    float StartMovementTime,
    EAresAlliance AllianceFilter)
{
    return;
}

void UEffectManagerComponent::ClientStopContinuousEffect(
    const FEffectID& EffectID,
    APlayerController* ClientControllerThatTriggered,
    EStopEffectType StopEffectType,
    float StopMovementTime)
{
    return;
}

void UEffectManagerComponent::ClientUpdateContinuousEffect(
    const FEffectID& EffectID,
    const FEffectData& EffectData,
    APlayerController* ClientControllerThatTriggered)
{
    return;
}

void UEffectManagerComponent::OnBecomeRelevant(AActor* OwningActor)
{
    return;
}

void UEffectManagerComponent::OnServerLeaveFoW(
    AActor* OwningActor,
    const AAresPlayerController* Viewer,
    EFoWRelevancyResult Relevance,
    EFoWRelevancyResult OldRelevance)
{
    return;
}

void UEffectManagerComponent::OnStopBeingRelevant(AActor* OwningActor)
{
    return;
}

void UEffectManagerComponent::PostMovementUpdate(float Timestamp)
{
    return;
}

void UEffectManagerComponent::PreMovementUpdate(float Timestamp)
{
    return;
}

void UEffectManagerComponent::StartDeferredEffects()
{
    return;
}

void UEffectManagerComponent::StopContinuousEffect(
    const FEffectID& EffectID,
    EStopEffectType StopEffectType)
{
    return;
}

void UEffectManagerComponent::StopContinuousEffectsOfType(
    TSubclassOf<AEffectContainer> EffectContainer,
    EStopEffectType StopEffectType)
{
    return;
}