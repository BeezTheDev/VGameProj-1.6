#include "CountdownTimerComponent.h"
#include "Net/UnrealNetwork.h"

void UCountdownTimerComponent::OnRep_AuthInitTime(float PreviousAuthInitTime)
{
}

void UCountdownTimerComponent::OnRep_AuthTime(float PreviousAuthTime)
{
}

void UCountdownTimerComponent::OnRep_AuthTimerState(const FTimerState& PreviousAuthTimerState)
{
}

void UCountdownTimerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UCountdownTimerComponent, AuthTime);
	DOREPLIFETIME(UCountdownTimerComponent, AuthInitTime);
	DOREPLIFETIME(UCountdownTimerComponent, AuthTimerState);
}