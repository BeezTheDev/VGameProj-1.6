#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ZoomTransitionSettings.h"
#include "ZoomLevelInfo.h"
#include "ZoomTransition.h"
#include "ZoomComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnZoomInStarted, class UZoomComponent*, ZoomComponent, float, TargetZoomLevel, bool, IsInitialZoom);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnZoomInCompleted, class UZoomComponent*, ZoomComponent, float, TargetZoomLevel, bool, IsInitialZoom);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUnZoomStarted, class UZoomComponent*, ZoomComponent, float, SourceZoomLevel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUnZoomCompleted, class UZoomComponent*, ZoomComponent, float, SourceZoomLevel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSyncToAuthValues, class UZoomComponent*, ZoomComponent, int32, CorrectedZoomLevel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCosmeticZoomInPercent, class UZoomComponent*, ZoomComponent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnZoomCooldownCompleted, class UZoomComponent*, ZoomComponent);

UCLASS()
class UZoomComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable)
	FOnZoomInStarted OnZoomInStarted;

	UPROPERTY(BlueprintAssignable)
	FOnZoomInCompleted OnZoomInCompleted;

	UPROPERTY(BlueprintAssignable)
	FOnUnZoomStarted OnUnZoomStarted;

	UPROPERTY(BlueprintAssignable)
	FOnUnZoomCompleted OnUnZoomCompleted;

	UPROPERTY(BlueprintAssignable)
	FOnSyncToAuthValues OnSyncToAuthValues;

	UPROPERTY(BlueprintAssignable)
	FOnCosmeticZoomInPercent OnCosmeticZoomInPercent;

	UPROPERTY(BlueprintAssignable)
	FOnZoomCooldownCompleted OnZoomCooldownCompleted;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FZoomTransitionSettings ZoomTransitionSettings;

	UPROPERTY(EditAnywhere)
	class UCurveFloat* ZoomInCurve;

	UPROPERTY(EditAnywhere)
	class UCurveFloat* ZoomOutCurve;

	UPROPERTY()
	TArray<FZoomLevelInfo> ZoomLevelInfo;

	UPROPERTY()
	FZoomTransition AuthZoomTransition;

	UPROPERTY()
	FZoomTransition ClientPredictedZoomTransition;

	UPROPERTY()
	class UValueDisagreementTimer* ClientPredictedValueDisagreementTimer;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UValueDisagreementTimer> ClientPredictedValueDisagreementTimerClassOverride;
};