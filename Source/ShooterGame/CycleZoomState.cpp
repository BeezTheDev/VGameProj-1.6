#include "CycleZoomState.h"

void UCycleZoomState::SetReturnState(UStateComponent* State)
{
}

bool UCycleZoomState::CanZoom() const
{
	return false;
}

float UCycleZoomState::GetCooldownTimeRemaining() const
{
	return 0.0f;
}

bool UCycleZoomState::IsAnyTriggerHeld() const
{
	return false;
}

bool UCycleZoomState::IsOnCooldown() const
{
	return false;
}

bool UCycleZoomState::IsReleaseInput(EAresEquippableInput Input, EAresEquippableInputAction InputAction) const
{
	return false;
}

bool UCycleZoomState::IsTriggerInput(EAresEquippableInput Input, EAresEquippableInputAction InputAction) const
{
	return false;
}