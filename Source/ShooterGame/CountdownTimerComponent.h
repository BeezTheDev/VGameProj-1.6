#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CountdownTimerComponent.generated.h"

struct FTimerState;

UCLASS()
class SHOOTERGAME_API UCountdownTimerComponent : public UActorComponent
{
	GENERATED_BODY()

private:

	UPROPERTY(ReplicatedUsing = OnRep_AuthTime)
	float AuthTime;

	UPROPERTY(ReplicatedUsing = OnRep_AuthInitTime)
	float AuthInitTime;

	UPROPERTY(ReplicatedUsing = OnRep_AuthTimerState)
	FTimerState AuthTimerState;

	UPROPERTY()
	float ClientPredictedTime;

	UPROPERTY()
	float ClientInitTime;

	UPROPERTY()
	FTimerState ClientTimerState;

	UPROPERTY()
	float AllowedClientPredictionTimeDrift;

public:

	UFUNCTION()
	void OnRep_AuthInitTime(float PreviousAuthInitTime);

	UFUNCTION()
	void OnRep_AuthTime(float PreviousAuthTime);

	UFUNCTION()
	void OnRep_AuthTimerState(const FTimerState& PreviousAuthTimerState);

protected:

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};