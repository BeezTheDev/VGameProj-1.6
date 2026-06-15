#pragma once

#include "CoreMinimal.h"
#include "ScriptStateComponent.h"
#include "WaitForEquipStateComponent.generated.h"

UCLASS()
class SHOOTERGAME_API UWaitForEquipStateComponent final : public UScriptStateComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	bool bTriggersAbilityExecution;
};