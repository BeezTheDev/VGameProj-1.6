#pragma once

#include "CoreMinimal.h"
#include "EAresEquippableInput.h"
#include "EAresEquippableInputAction.h"
#include "TriggerInput.generated.h"

USTRUCT(BlueprintType)
struct FTriggerInput
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EAresEquippableInput TriggerInput;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EAresEquippableInputAction TriggerAction;
};