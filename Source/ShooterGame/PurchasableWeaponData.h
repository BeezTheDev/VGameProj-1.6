#pragma once

#include "CoreMinimal.h"
#include "PurchasableWeaponData.generated.h"

UCLASS(BlueprintType)
class SHOOTERGAME_API UPurchasableWeaponData : public UObject
{
    GENERATED_BODY()

public:

    UPROPERTY(BlueprintReadOnly)
    float MaxDamage;

    UPROPERTY(BlueprintReadOnly)
    float MinDamage;

    UPROPERTY(BlueprintReadOnly)
    float FarthestRangeForMaxDamage;

    UPROPERTY(BlueprintReadOnly)
    float ClostedRangeForMinDamage;

    UPROPERTY(BlueprintReadOnly)
    float HeadshotMultiplier;

    UPROPERTY(BlueprintReadOnly)
    float MinSpread;

    UPROPERTY(BlueprintReadOnly)
    float MaxSpread;

    UPROPERTY(BlueprintReadOnly)
    float FiringRate;

    UPROPERTY(BlueprintReadOnly)
    float MagazineSize;

    UPROPERTY(BlueprintReadOnly)
    float ReloadSpeed;

    UPROPERTY(BlueprintReadOnly)
    float MovementSpeed;

    UPROPERTY(BlueprintReadOnly)
    float ReadyTime;
};