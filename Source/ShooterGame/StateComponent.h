#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StateComponent.generated.h"

class UStateMachineComponent;

UCLASS()
class SHOOTERGAME_API UStateComponent : public UActorComponent
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly)
	bool bAutoAddToStateMachine;

public:

	void CheckStateMachine(AActor* Owner);

	bool IsCurrentState() const;
};