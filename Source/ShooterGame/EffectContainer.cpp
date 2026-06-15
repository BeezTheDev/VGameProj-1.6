#include "EffectContainer.h"

void AEffectContainer::AddTailTime(float TailTime)
{
}

void AEffectContainer::EffectDataUpdated()
{
}

void AEffectContainer::EquippablePerspectiveChanged(AAresEquippable* Equippable, bool bFirstPersonVisible, bool bThirdPersonVisible)
{
}

void AEffectContainer::OnMontageStartedByCosmeticFXC(UAnimMontage* Montage)
{
}

void AEffectContainer::OwnerHiddenChanged(AActor* Actor)
{
}

void AEffectContainer::PerspectiveChanged(AShooterCharacter* Character)
{
}

void AEffectContainer::ResetEffect()
{
}

void AEffectContainer::StartEffect(AActor* Target, UObject* Context, float StartTime, bool FirstPerson)
{
}

void AEffectContainer::StartPlacedEffectContainer()
{
}

void AEffectContainer::StopEffect(EStopEffectType StopEffectType)
{
}

void AEffectContainer::UpdateEffectPerspective(float CurrentTime, bool FirstPerson)
{
}

float AEffectContainer::GetElapsedEffectTime() const
{
	return 0.0f;
}