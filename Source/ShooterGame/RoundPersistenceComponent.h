#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RoundPersistenceBehavior.h"
#include "RoundPersistenceComponent.generated.h"

UCLASS()
class SHOOTERGAME_API URoundPersistenceComponent final : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	RoundPersistenceBehavior PersistBehavior;

	UPROPERTY()
	bool bPersistedThisRound;
};