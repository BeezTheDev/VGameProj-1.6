#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoundPersistenceComponent.h" 
#include "AresItemSlot.h"
#include "ShooterCharacter.h"
#include "EEquippableInInventory.h"
#include "BaseContentUIData.h"
#include "AresItem.generated.h"

class UReplicationSleepComponent;
class UAresBasePrimaryDataAsset;
class UTexture;

enum class EEquippableInInventory : uint8;
enum class EInventoryTransaction : uint8;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAresItemOnSetOwner, AAresItem*, Item, AActor*, PrevOwner, AActor*, NewOwner);

UCLASS()
class SHOOTERGAME_API AAresItem : public AActor
{
    GENERATED_BODY()

public:

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    int32 MaximumAmount;

    UPROPERTY(BlueprintAssignable)
    FAresItemOnSetOwner AuthItemOnSetOwner;

    UPROPERTY(BlueprintAssignable)
    FAresItemOnSetOwner ItemOnSetOwner;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
    URoundPersistenceComponent* Persistence;

protected:

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    EAresItemSlot EquippableSlot;

    UPROPERTY(BlueprintReadOnly)
    AShooterCharacter* MyPawn;

    UPROPERTY(BlueprintReadOnly)
    EEquippableInInventory InInventory;

    UPROPERTY(BlueprintReadOnly, Replicated)
    FString OriginalOwnerName;

    UPROPERTY(BlueprintReadOnly)
    FString OriginalOwnerId;

    UPROPERTY(Transient)
    TWeakObjectPtr<UAresBasePrimaryDataAsset> CachedDataAsset;

    UPROPERTY(Transient)
    TWeakObjectPtr<UBaseContentUIData> CachedUIData;

public:

    static FString GetAssetServiceIDFromClass(const UObject* WorldContextObject, UClass* ItemClass);

    void AuthDestroyInternal();
    void AuthRemoveAndDestroy(EInventoryTransaction TransactionType);
    void AuthSetOwnerTo(AActor* NewOwner);
    FString GetAssetServiceID();
    int32 GetSellPrice(int32 BasePrice);
    void OverrideUIData(TSubclassOf<UBaseContentUIData> OverriddenUIData);

    UFUNCTION(BlueprintNativeEvent)
    void ReceiveAuthClearOwningCharacter(AShooterCharacter* OldCharacter);

    UFUNCTION(BlueprintNativeEvent)
    void ReceiveAuthSetOwningCharacter(AShooterCharacter* NewCharacter);

    UFUNCTION(BlueprintNativeEvent)
    void ReceiveClientClearOwningCharacter(AShooterCharacter* OldCharacter);

    UFUNCTION(BlueprintNativeEvent)
    void ReceiveClientSetOwningCharacter(AShooterCharacter* NewCharacter);

    void ClientDebugDrawTextOnScreen(const FString& DrawText, const FLinearColor& DrawColor, float DurationOverride) const;
    UTexture* GetItemIcon() const;
    FText GetItemNameText() const;
    EAresItemSlot GetItemSlot() const;
    FText GetItemTooltipText() const;
    FString GetOriginalOwnerId() const;
    FString GetOriginalOwnerName() const;
    AShooterCharacter* GetPawnOwner() const;
    bool IsEquippable() const;

protected:

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};