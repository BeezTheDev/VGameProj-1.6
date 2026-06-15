#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/Widget.h"
#include "BaseContentUIData.generated.h"

class UTexture;

UCLASS()
class SHOOTERGAME_API UBaseContentUIData : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Description;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UTexture* DisplayIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FWidgetTransform IconTransform;

private:

	UPROPERTY(Transient)
	TWeakObjectPtr<UObject> WorldContext;
};