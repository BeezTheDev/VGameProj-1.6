#include "EquippableStateComponent.h"

void UEquippableStateComponent::AuthSetOverrideFogOfWarWhileInState(bool bNewOverrideFogOfWarWhileInState)
{
}

AAresPlayerController* UEquippableStateComponent::GetOwningAresPlayerController() const
{
	return nullptr;
}

ACharacter* UEquippableStateComponent::GetOwningCharacter() const
{
	return nullptr;
}

AAresEquippable* UEquippableStateComponent::GetOwningEquippable() const
{
	return nullptr;
}

UEquippableStateMachineComponent* UEquippableStateComponent::GetOwningEquippableStateMachineComponent() const
{
	return nullptr;
}

AShooterCharacter* UEquippableStateComponent::GetOwningShooterCharacter() const
{
	return nullptr;
}

AShooterPlayerController* UEquippableStateComponent::GetOwningShooterPlayerController() const
{
	return nullptr;
}

bool UEquippableStateComponent::ShouldUseFirstPersonPerspective() const
{
	return false;
}