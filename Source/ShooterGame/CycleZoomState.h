#pragma once

#include "CoreMinimal.h"
#include "ScriptStateComponent.h"
#include "TriggerInput.h"
#include "InitialZoomLevelContext.h"
#include "CycleZoomState.generated.h"

class UZoomManagerComponent;
class UInitialZoomLevelContext;
class UStateComponent;
struct FTriggerInput;
enum class EAresEquippableInput : uint8;
enum class EAresEquippableInputAction : uint8;

UCLASS()
class SHOOTERGAME_API UCycleZoomState final : public UScriptStateComponent
{
	GENERATED_BODY()

private:

	UPROPERTY()
	UZoomManagerComponent* ZoomManagerComponent;

	UPROPERTY(EditDefaultsOnly)
	TArray<FTriggerInput> ZoomTriggerInputs;

	UPROPERTY()
	UInitialZoomLevelContext* ZoomLevelContext;

public:

	void SetReturnState(UStateComponent* State);

	bool CanZoom() const;
	float GetCooldownTimeRemaining() const;
	bool IsAnyTriggerHeld() const;
	bool IsOnCooldown() const;
	bool IsReleaseInput(EAresEquippableInput Input, EAresEquippableInputAction InputAction) const;
	bool IsTriggerInput(EAresEquippableInput Input, EAresEquippableInputAction InputAction) const;
};