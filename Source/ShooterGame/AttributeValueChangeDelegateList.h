#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AttributeValueChangeDelegateList.generated.h"

DECLARE_DELEGATE_ThreeParams(FAttributeValueChangedDelegate, FGameplayAttribute&, float, float);

USTRUCT()
struct FAttributeValueChangeDelegateList
{
	GENERATED_BODY()

public:

	TArray<FAttributeValueChangedDelegate> Delegates;
};