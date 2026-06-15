#pragma once

#include "CoreMinimal.h"
#include "AresItem.h"

#include "AnimSlot1P.h"
#include "AnimSlotGun1P.h"
#include "Sound/SoundCue.h"
#include "AnimSlotUpperBody3P.h"
#include "EEquippableEquipBehavior.h"
#include "AnimSlotLowerBody3P.h"
#include "EZoomInHideOption.h"
#include "EZoomOutShowOption.h"
#include "AnimSlotFace3P.h"
#include "EAresDropOnDeath.h"
#include "PendingReplicationEffect.h"
#include "AsyncLoadedEquippableCharacterAnim.h"
#include "AsyncLoadedEquippableGunAnim.h"
#include "EquippableStateMachineComponent.h"
#include "UsablePriority.h"
#include "EquippableSkinDataAsset.h"
#include "EquippableSkinLevelDataAsset.h"
#include "EquippableAttachmentDataAsset.h"
#include "EquippableSkinChromaDataAsset.h"
#include "EEquippableRejectInputReason.h"
#include "EquippableCharmDataAsset.h"
#include "EquippableCharmLevelDataAsset.h"
#include "KillBannerData.h"
#include "CooldownComponent.h"
#include "EquippableFogOfWarComponent.h"
#include "CycleZoomState.h"
#include "EEquippableTickState.h"

#include "AresEquippable.generated.h"

class UTexture;
class UAnimationAsset;
class UAkAudioEvent;
class AShooterCharacter;
class AEffectContainer;
class USceneComponent;
class USkeletalMeshComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEquippableRejectedInput, AAresEquippable*, Equippable, EEquippableRejectInputReason, Reason);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnItemEquipped);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnItemUnequipped);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEquippableOnSetOwner, AAresEquippable*, Equippable, AActor*, Owner);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnMeshVisibilityUpdated, AAresEquippable*, Equippable, bool, bFirstPersonVisible, bool, bThirdPersonVisible);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDisabledInputRequested);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEquippableDisabled);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEquippableDropped, AAresEquippable*, Equippable);

UCLASS(Blueprintable)
class SHOOTERGAME_API AAresEquippable final : public AAresItem
{
    GENERATED_BODY()

protected:

    UPROPERTY()
    EEquippableTickState EquippableTickState;

public:

    UPROPERTY(EditDefaultsOnly)
    UTexture* ObjectiveIcon;

    UPROPERTY(BlueprintReadWrite)
    bool bUsingCharacterAlternateAnims;

    UPROPERTY(EditDefaultsOnly)
    TMap<TSubclassOf<UAnimSlot1P>, TSoftObjectPtr<UAnimationAsset>> CharacterAnims1P;

    UPROPERTY(EditDefaultsOnly)
    TMap<TSubclassOf<UAnimSlot1P>, TSoftObjectPtr<UAnimationAsset>> CharacterAnimsAltmode1P;

    UPROPERTY()
    TMap<TSubclassOf<UAnimSlot1P>, TSoftObjectPtr<UAnimationAsset>> CharacterAnimsAltmode1POverride;

    UPROPERTY()
    TMap<TSubclassOf<UAnimSlot1P>, TSoftObjectPtr<UAnimationAsset>> CharacterAnims1POverride;

    UPROPERTY()
    TMap<TSubclassOf<UAnimSlotGun1P>, TSoftObjectPtr<UAnimationAsset>> GunAnims1POverride;

    UPROPERTY()
    TMap<TSubclassOf<UAnimSlotGun1P>, TSoftObjectPtr<UAnimationAsset>> CosmeticGunAnims1POverride;

    UPROPERTY()
    TMap<TSubclassOf<UAnimSlotGun1P>, TSoftObjectPtr<UAnimationAsset>> CosmeticGunAnimsAltmode1POverride;

    UPROPERTY()
    TMap<TSubclassOf<UAnimSlotLowerBody3P>, UAnimationAsset*> CharacterAnimsLowerBody3POverride;

    UPROPERTY()
    TMap<TSubclassOf<UAnimSlotUpperBody3P>, UAnimationAsset*> CharacterAnimsUpperBody3POverride;

    UPROPERTY(EditDefaultsOnly)
    TMap<TSubclassOf<UAnimSlotGun1P>, TSoftObjectPtr<UAnimationAsset>> GunAnims1P;

    UPROPERTY(EditDefaultsOnly)
    TMap<TSubclassOf<UAnimSlotUpperBody3P>, UAnimationAsset*> CharacterAnimsUpperBody3P;

    UPROPERTY(EditDefaultsOnly)
    TMap<TSubclassOf<UAnimSlotUpperBody3P>, UAnimationAsset*> CharacterAnimsAltModeUpperBody3P;

    UPROPERTY(EditDefaultsOnly)
    TMap<TSubclassOf<UAnimSlotLowerBody3P>, UAnimationAsset*> CharacterAnimsLowerBody3P;

    UPROPERTY(EditDefaultsOnly)
    TMap<TSubclassOf<UAnimSlotLowerBody3P>, UAnimationAsset*> CharacterAnimsAltModeLowerBody3P;

    UPROPERTY(EditDefaultsOnly)
    TMap<TSubclassOf<UAnimSlotFace3P>, UAnimationAsset*> CharacterAnimsFace3P;

    UPROPERTY(EditDefaultsOnly)
    TMap<TSubclassOf<UAnimSlotFace3P>, UAnimationAsset*> CharacterAnimsAltModeFace3P;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool LeftHandIKEnabled;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    bool RightHandIKEnabled;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float InaccuracyAnimationMultiplier;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float PrimaryAimSpring1PStiffness;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float PrimaryAimSpring1PDampening;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float SecondaryAimSpring1PStiffness;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float SecondaryAimSpring1PDampening;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    USoundCue* PickupSoundEvent;

    UPROPERTY(BlueprintAssignable)
    FOnEquippableRejectedInput OnRejectedInput;

protected:

    UPROPERTY(Transient)
    TMap<TSubclassOf<UAnimSlot1P>, FAsyncLoadedEquippableCharacterAnim> CachedCharacterAnimationAssetMap;

    UPROPERTY(Transient)
    TMap<TSubclassOf<UAnimSlotGun1P>, FAsyncLoadedEquippableGunAnim> CachedGunAnimationAssetMap;

    UPROPERTY(Transient)
    TWeakObjectPtr<AShooterCharacter> AttributeOwner;

public:

    UPROPERTY(BlueprintAssignable)
    FOnItemEquipped OnItemEquipped;

    UPROPERTY(BlueprintAssignable)
    FOnItemUnequipped OnItemUnequipped;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float EquipQueueTime;

    UPROPERTY(EditDefaultsOnly)
    bool bCanBeAutoEquipped;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    bool bCanBeEquippedOutsideGameplay;

    UPROPERTY(BlueprintAssignable)
    FEquippableOnSetOwner EquippableOnSetOwner;

protected:

    UPROPERTY(EditDefaultsOnly)
    EEquippableEquipBehavior EquipBehavior;

    UPROPERTY(EditDefaultsOnly)
    bool OverrideHolstering;

public:

    UPROPERTY(BlueprintAssignable)
    FOnMeshVisibilityUpdated OnMeshVisibilityUpdated;

    UPROPERTY(Transient)
    TArray<FString> PostInitErrors;

    UPROPERTY()
    TMap<TSoftClassPtr<UClass>, TSubclassOf<AEffectContainer>> EffectOverrides;

    UPROPERTY(VisibleInstanceOnly)
    UZoomManagerComponent* ZoomManager;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    bool bAutoEquip;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    bool bAutoPickup;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float AutoPickupDistance;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float PreventPickupDuration;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float ScaleOnGround;

    UPROPERTY(VisibleInstanceOnly)
    UCooldownComponent* CooldownComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    bool bCanActivateWhenSlotDisabled;

    UPROPERTY(BlueprintAssignable)
    FOnDisabledInputRequested OnDisabledInputRequested;

    UPROPERTY(BlueprintAssignable)
    FOnEquippableDisabled OnEquippableDisabled;

    UPROPERTY(BlueprintReadWrite, Transient)
    bool bDestroyWhenDropped;

    UPROPERTY(BlueprintAssignable)
    FOnEquippableDropped OnDropped;

    UPROPERTY(ReplicatedUsing = OnRep_InPersistentData, Transient)
    bool bInPersistentData;

protected:

    UPROPERTY(EditDefaultsOnly)
    bool bHideFirstPersonWhileZoomed;

    UPROPERTY(EditDefaultsOnly)
    EZoomInHideOption ZoomInHideOption;

    UPROPERTY(EditDefaultsOnly)
    EZoomOutShowOption ZoomOutShowOption;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float ZoomedMovementRatio;

    UPROPERTY(EditDefaultsOnly)
    float AlwaysTurnRatio;

    UPROPERTY(EditDefaultsOnly)
    float AlwaysMovementRatio;

    UPROPERTY(EditDefaultsOnly)
    FName EquippableAttachPoint1P;

    UPROPERTY(EditDefaultsOnly)
    FName EquippableAttachPoint3P;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
    USceneComponent* MySceneRoot;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
    USceneComponent* MyRoot3P;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
    USkeletalMeshComponent* Mesh1P;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
    USkeletalMeshComponent* Mesh3P;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
    UEquippableStateMachineComponent* EquippableStateMachine;

    UPROPERTY(VisibleInstanceOnly)
    UEquippableFogOfWarComponent* EquippableFogOfWar;

    UPROPERTY(VisibleInstanceOnly)
    UCycleZoomState* EquippableCycleZoomState;

    UPROPERTY(Transient)
    TArray<UEquippableStateMachineComponent*> EquippableStateMachines;

    UPROPERTY()
    TArray<USkeletalMeshComponent*> Meshes;

    UPROPERTY(EditDefaultsOnly)
    FName InventoryAttachPoint;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    bool bCanBeDropped;

    UPROPERTY(EditDefaultsOnly)
    bool bDropOnDeath;

    UPROPERTY(EditDefaultsOnly)
    EAresDropOnDeath DropOnDeathNew;

    UPROPERTY(EditDefaultsOnly)
    FRotator DropOnDeathScatterMin;

    UPROPERTY(EditDefaultsOnly)
    FRotator DropOnDeathScatterMax;

    UPROPERTY(EditDefaultsOnly)
    bool bOnlyAlliesCanPickup;

    UPROPERTY(meta = (DeprecatedProperty))
    EUsablePriority PickupPriority;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float PickupScoringBonus;

    UPROPERTY(EditDefaultsOnly)
    FName MuzzlePointSocketName;

public:

    UPROPERTY(BlueprintReadWrite)
    TSubclassOf<UKillBannerData> SkinKillBannerData;

protected:

    UPROPERTY(EditDefaultsOnly)
    UTexture* InventoryIcon;

    UPROPERTY(Transient)
    UEquippableSkinDataAsset* SkinDataAsset;

    UPROPERTY(Transient)
    UEquippableSkinLevelDataAsset* SkinLevelDataAsset;

    UPROPERTY(Transient)
    TArray<UEquippableAttachmentDataAsset*> AttachmentDataAssets;

    UPROPERTY(Transient)
    UEquippableSkinChromaDataAsset* ChromaDataAsset;

    UPROPERTY(Transient)
    UEquippableCharmDataAsset* CharmDataAsset;

    UPROPERTY(Transient)
    UEquippableCharmLevelDataAsset* CharmLevelDataAsset;

    UPROPERTY(Transient)
    FGuid SkinDataAssetId;

    UPROPERTY(Transient)
    FGuid SkinLevelDataAssetId;

    UPROPERTY(Transient)
    FGuid CharmDataAssetId;

    UPROPERTY(Transient)
    FGuid CharmLevelDataAssetId;

    UPROPERTY(Transient)
    TArray<FGuid> AttachmentDataAssetIds;

    UPROPERTY(Transient)
    FGuid ChromaDataAssetId;

    UPROPERTY(Transient)
    AShooterCharacter* PreventPickupCharacter;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    bool bInitialCooldownOnRoundStart;

    UPROPERTY()
    bool bAuthIsGhostEquipped;

public:

    UPROPERTY(meta = (DeprecatedProperty))
    int32 MaxCharges;

    UPROPERTY(meta = (DeprecatedProperty))
    int32 ChargesGainedEachRefresh;

    UPROPERTY()
    float AuthHitRegistrationSubTickMovementTimestamp;

    UPROPERTY()
    float AuthHitRegistrationStartOfFrameSubTickMovementTimestamp;

    UPROPERTY()
    float AuthServerSnapshottedMovementTimestamp;

private:

    UPROPERTY(Transient)
    TArray<TWeakObjectPtr<UObject>> HolsterBlockingObjects;

    UPROPERTY(Transient)
    bool bIsForced1PTextureStreamingEnabled;

protected:

    UFUNCTION()
    void OnRep_InPersistentData();
};