#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StateMachineComponent.generated.h"

UCLASS()
class SHOOTERGAME_API UStateMachineComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override {}
};