#pragma once

#include "CoreMinimal.h"
#include "StateComponent.h"
#include "EquippableStateComponent.generated.h"

class UValueDisagreementTimer;
class AAresPlayerController;
class ACharacter;
class AAresEquippable;
class UEquippableStateMachineComponent;
class AShooterCharacter;
class AShooterPlayerController;
struct FItemSlotBlocking;
enum class EStateBehaviorOnUnequip : uint8;

UCLASS()
class SHOOTERGAME_API UEquippableStateComponent : public UStateComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bEquippableUsedState;

protected:

	UPROPERTY(EditDefaultsOnly)
	bool bRequiresTick;

	UPROPERTY(EditDefaultsOnly)
	bool bRequiresReplication;

	UPROPERTY(EditDefaultsOnly)
	FItemSlotBlocking EquipBlocking;

	UPROPERTY(EditDefaultsOnly)
	FItemSlotBlocking ActivationInputBlocking;

	UPROPERTY(EditDefaultsOnly)
	EStateBehaviorOnUnequip UnequipBehavior;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UValueDisagreementTimer> ClientPredictedValueDisagreementTimerClassOverride;

	UPROPERTY()
	UValueDisagreementTimer* ClientPredictedValueDisagreementTimer;

	UPROPERTY(EditDefaultsOnly)
	bool bOverrideFogOfWarWhileInState;

	UPROPERTY(EditDefaultsOnly)
	float FogOfWarAudibleDistance;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay)
	float FogOfWarOutroTime;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay)
	float FogOfWarMaxStateDuration;

public:

	void AuthSetOverrideFogOfWarWhileInState(bool bNewOverrideFogOfWarWhileInState);

	AAresPlayerController* GetOwningAresPlayerController() const;
	ACharacter* GetOwningCharacter() const;
	AAresEquippable* GetOwningEquippable() const;
	UEquippableStateMachineComponent* GetOwningEquippableStateMachineComponent() const;
	AShooterCharacter* GetOwningShooterCharacter() const;
	AShooterPlayerController* GetOwningShooterPlayerController() const;
	bool ShouldUseFirstPersonPerspective() const;
};