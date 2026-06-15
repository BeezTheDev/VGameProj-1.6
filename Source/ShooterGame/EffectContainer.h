#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "EEffectAttachType.h"
#include "ESpawnEffectType.h"
#include "EMovementSyncType.h"
#include "EStopEffectType.h"
#include "EffectData.h"

#include "EffectContainer.generated.h"

class AAresEquippable;
class AShooterCharacter;
class UEffectManagerComponent;
class UAnimMontage;
class UObject;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnStartEffect, AActor*, Target, UObject*, Context, float, StartTime, bool, FirstPerson);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUpdateEffectPerspective, float, StartTime, bool, FirstPerson);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEffectDataUpdated);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStopEffect, EStopEffectType, StopEffectType);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnResetEffect);

UCLASS()
class SHOOTERGAME_API AEffectContainer : public AActor
{
    GENERATED_BODY()

public:

    UPROPERTY(BlueprintReadOnly, Transient)
    FEffectData EffectID;

    UPROPERTY(BlueprintReadOnly, Transient)
    FEffectData EffectData;

    UPROPERTY(BlueprintAssignable)
    FOnStartEffect OnStartEffect;

    UPROPERTY(BlueprintAssignable)
    FOnUpdateEffectPerspective OnUpdateEffectPerspective;

    UPROPERTY(BlueprintAssignable)
    FOnEffectDataUpdated OnEffectDataUpdated;

    UPROPERTY(BlueprintAssignable)
    FOnStopEffect OnStopEffect;

    UPROPERTY(BlueprintAssignable)
    FOnResetEffect OnResetEffect;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    EEffectAttachType AttachType;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    bool bObeyOwnerHidden;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay)
    EMovementSyncType MovementSyncType;

    UPROPERTY(meta = (DeprecatedProperty))
    bool bPureEffect;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay)
    ESpawnEffectType SpawnType;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay)
    bool bCosmeticEffect;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (EditCondition = "false"))
    bool bCurrentPerspectiveIsFirstPerson;

protected:

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float EffectTailTime;

private:

    UPROPERTY(Transient)
    AEffectContainer* PureEffectInstance;

    UPROPERTY(Transient)
    UEffectManagerComponent* OwningManager;

    UPROPERTY(Transient)
    AActor* OriginalTarget;

public:

    void AddTailTime(float TailTime);
    void EffectDataUpdated();
    void EquippablePerspectiveChanged(AAresEquippable* Equippable, bool bFirstPersonVisible, bool bThirdPersonVisible);
    void OnMontageStartedByCosmeticFXC(UAnimMontage* Montage);
    void OwnerHiddenChanged(AActor* Actor);
    void PerspectiveChanged(AShooterCharacter* Character);
    void ResetEffect();
    void StartEffect(AActor* Target, UObject* Context, float StartTime, bool FirstPerson);
    void StartPlacedEffectContainer();
    void StopEffect(EStopEffectType StopEffectType);
    void UpdateEffectPerspective(float CurrentTime, bool FirstPerson);

    float GetElapsedEffectTime() const;
};