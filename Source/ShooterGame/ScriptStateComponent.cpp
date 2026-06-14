#include "ScriptStateComponent.h"

void UScriptStateComponent::GoToNextState(float TimeUntilTransition)
{
}

void UScriptStateComponent::GoToState(UStateComponent* NewState, float TimeUntilTransition)
{
}

void UScriptStateComponent::GoToStateWithContext(UStateComponent* NewState, UStateTransitionContext* Context, float TimeUntilTransition)
{
}

void UScriptStateComponent::OnSyncToAuthValues()
{
}

void UScriptStateComponent::SetCurrentContext(UStateTransitionContext* NewContext)
{
}

void UScriptStateComponent::SetCustomContext(UObject* NewContext)
{
}

void UScriptStateComponent::SetDefaultNextState(UStateComponent* State)
{
}

UStateTransitionContext* UScriptStateComponent::SetNewContext(TSubclassOf<UStateTransitionContext> ContextType)
{
	return nullptr;
}

UStateTransitionContext* UScriptStateComponent::GetCurrentContext() const
{
	return nullptr;
}

UStateComponent* UScriptStateComponent::GetDefaultNextState() const
{
	return nullptr;
}