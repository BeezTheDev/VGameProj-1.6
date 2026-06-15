#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FogOfWarComponent.generated.h"

class AEffectContainer;
class UFogOfWarBoundsComponent;
class UFogOfWarDebugComponent;
class UFogOfWarManagerComponent;
class UViewerFogOfWarComponent;
struct FEffectData;

UCLASS()
class SHOOTERGAME_API UFogOfWarComponent : public UActorComponent
{
    GENERATED_BODY()

protected:
    
    UPROPERTY(EditAnywhere)
    bool bBoundsIncludesOnlyCollidingComponents;

    UPROPERTY(EditAnywhere)
    bool bUseCachedBounds;
    
    UPROPERTY(EditDefaultsOnly)
    float LookAheadTime;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<AEffectContainer> DebugWallhackEffectClass;

    UPROPERTY()
    bool bOwnerIsRelevantToClient;

    UPROPERTY()
    bool bOwnerIsHiddenForClient;
    
    UPROPERTY()
    bool bReceivedNetUpdate;

private:

    UPROPERTY()
    TArray<AActor*> CachedAttachedActors;

    UPROPERTY()
    TArray<UFogOfWarComponent*> CachedAttachedFoWComponents;

    UPROPERTY()
    bool bCacheNeedsRebuilding;

public:

    int32 AddAudioEvent(float AudibleDistance, float Duration);
    int32 AddRelevancyOverride(float Duration);
    void AuthSetCharacterNeverRelevant(bool bNewNeverRelevant);
    void OnOwnerAttachTreeChanged(USceneComponent* AttachedComponent, bool bAttached);
    void OnTeamChanged();
    void OnViewerComponentDestroyed(UViewerFogOfWarComponent* DestroyedComponent);
    void RemoveAudioEvent(int32 Handle);
    bool RemoveRelevancyOverride(int32 Handle);

    bool IsHiddenForLocalClient() const;
    bool IsRelevantForLocalClient() const;
};