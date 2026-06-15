#pragma once

#include "CoreMinimal.h"
#include "EStateBehaviorOnDeath.h"
#include "StateMachineComponent.h"
#include "EquippableStateBuffInfo.h"
#include "EquippableStateMachineComponent.generated.h"

class URespondToEventStateComponent;
class UStateComponent;
class ACharacter;
class AAresEquippable;
class AShooterCharacter;
class AShooterPlayerController;

struct FEquippableStateBuffInfo;

UCLASS()
class SHOOTERGAME_API UEquippableStateMachineComponent final : public UStateMachineComponent
{
	GENERATED_BODY()

public:

	UPROPERTY()
	bool bStateMachineEnabled = false;

	UPROPERTY()
	URespondToEventStateComponent* InactiveState = nullptr;

	UPROPERTY()
	EStateBehaviorOnDeath DeathBehavior;

	UPROPERTY()
	UStateComponent* DeathState = nullptr;

	UPROPERTY()
	UStateComponent* CurrentStateForBuffs = nullptr;

	UPROPERTY()
	TArray<FEquippableStateBuffInfo> ActiveStateBuffs;

	UPROPERTY()
	float InputQueueTimeDurations[11] = {};

	UPROPERTY()
	bool bClientSimulationDesynced = false;

public:

	void AuthSetClientSimulationDesync();
	void OnItemMovedToPersistentData();
	void SetDeathState(UStateComponent* State);

	URespondToEventStateComponent* GetInactiveState() const;
	ACharacter* GetOwningCharacter() const;
	AAresEquippable* GetOwningEquippable() const;
	AShooterCharacter* GetOwningShooterCharacter() const;
	AShooterPlayerController* GetOwningShooterPlayerController() const;
};