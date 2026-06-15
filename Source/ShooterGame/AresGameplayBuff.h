#pragma once

#include "CoreMinimal.h"
#include "GamepLayEffect.h"
#include "AresTeamTargeting.h"
#include "EmbeddedEffectInfo.h"
#include "EBuffEffectContext.h"
#include "AresGameplayBuff.generated.h"

class UDamageType;

UCLASS()
class SHOOTERGAME_API UAresGameplayBuff final : public UGameplayEffect
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	FEmbeddedEffectInfo BuffEffect;

	UPROPERTY(EditDefaultsOnly)
	EBuffEffectContext ContextObject;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UDamageType> DamageType;

protected:

	UPROPERTY(EditDefaultsOnly)
	EAresTeamTargeting TeamTargeting;

public:

	static void ApplyRadialBuff(UObject* WorldContextObject, TSubclassOf<UAresGameplayBuff> BuffClass, const FVector& Origin, float Radius, AActor* DamageCauser, APawn* InstigatorPawn);

	EAresTeamTargeting GetTeamTargeting() const;
};