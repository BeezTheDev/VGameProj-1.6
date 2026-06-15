#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ZoomTransitionSettings.h"
#include "ZoomManagerComponent.generated.h"

class UZoomComponent;
class AAresEquippable;
class AShooterCharacter;
class AActor;

struct FZoomTransitionSettings;
struct FGameplayAttribute;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SHOOTERGAME_API UZoomManagerComponent final : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY()
	UZoomComponent* ZoomComponent = nullptr;

	UPROPERTY()
	FZoomTransitionSettings ZoomTransitionSettings;

	UPROPERTY()
	AShooterCharacter* CurrentOwningCharacter = nullptr;

public:

	static void UnZoom(AAresEquippable* Equippable, float TimeDuration);

	UZoomComponent* GetZoomComponent();

	void OnOwningEquippableSetOwner(AAresEquippable* Equippable, AActor* NewOwner);

	void OnOwningEquippableUnequipped();

	void OnZoomDisabledChanged(const FGameplayAttribute& Attribute, float OldValue, float NewValue);

	void SetZoomComponent(UZoomComponent* ZoomComponent_0);

	void UpdateAttributeBinding(AActor* NewOwner);
};