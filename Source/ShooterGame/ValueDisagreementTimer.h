#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "ValueDisagreementTimer.generated.h"

UCLASS()
class SHOOTERGAME_API UValueDisagreementTimer final : public UObject
{
	GENERATED_BODY()

private:

	UPROPERTY()
	bool bIsEnabled;
	
	UPROPERTY()
	float ValueUnchangedTimeDuration;

	UPROPERTY()
	bool bValueChangedSinceLastTick;

	UPROPERTY(EditDefaultsOnly)
	float ConsiderStablePingTimeMultiplier;

	UPROPERTY(EditDefaultsOnly)
	float ConsiderStableBufferTimeDurationMilliseconds;

	UPROPERTY(EditDefaultsOnly)
	float ConsiderStableMaxWaitTimeDurationMilliseconds;

public:

	void OnOwnerClientRoleChanged(AActor* Owner, ENetRole NewRole);
};