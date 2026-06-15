#pragma once

#include "CoreMinimal.h"
#include "QueuedStateTransition.generated.h"

class UStateComponent;
class UStateTransitionContext;

USTRUCT(BlueprintType)
struct FQueuedStateTransition
{
	GENERATED_BODY()

public:

	UPROPERTY()
	bool bIsSet = false;

	UPROPERTY()
	UStateComponent* QueuedNextState = nullptr;

	UPROPERTY()
	UStateTransitionContext* QueuedContext = nullptr;

	UPROPERTY()
	float TimeRemaining = 0.0f;
};