#include "FogOfWarComponent.h"

int32 UFogOfWarComponent::AddAudioEvent(float AudibleDistance, float Duration)
{
	return -1;
}

int32 UFogOfWarComponent::AddRelevancyOverride(float Duration)
{
	return -1;
}

void UFogOfWarComponent::AuthSetCharacterNeverRelevant(bool bNewNeverRelevant)
{
}

void UFogOfWarComponent::OnOwnerAttachTreeChanged(USceneComponent* AttachedComponent, bool bAttached)
{
}

void UFogOfWarComponent::OnTeamChanged()
{
}

void UFogOfWarComponent::OnViewerComponentDestroyed(UViewerFogOfWarComponent* DestroyedComponent)
{
}

void UFogOfWarComponent::RemoveAudioEvent(int32 Handle)
{
}

bool UFogOfWarComponent::RemoveRelevancyOverride(int32 Handle)
{
	return false;
}

bool UFogOfWarComponent::IsHiddenForLocalClient() const
{
	return false;
}

bool UFogOfWarComponent::IsRelevantForLocalClient() const
{
	return false;
}