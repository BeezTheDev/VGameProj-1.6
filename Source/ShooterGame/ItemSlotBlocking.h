#pragma once

#include "CoreMinimal.h"
#include "AresItemSlot.h"
#include "ItemSlotBlocking.generated.h"

USTRUCT(BlueprintType)
struct FItemSlotBlocking
{
	GENERATED_BODY()

private:

	UPROPERTY(EditDefaultsOnly)
	bool bBlockAll;

	UPROPERTY(EditDefaultsOnly)
	TArray<EAresItemSlot> BlockedItemSlots;
};