#pragma once

#include "CoreMinimal.h"
#include "EAresEquippableInput.h"
#include "EquippableStateComponent.h"
#include "ActiveScriptStateEffect.h"
#include "EquippableStateBuffInfo.h"
#include "EAresEquippableInputAction.h"
#include "ScriptStateEffectInfo.h"
#include "QueuedStateTransition.h"
#include "ScriptStateComponent.generated.h"

class UStateComponent;
class UStateTransitionContext;
struct FEquippableStateBuffInfo;
struct FActiveScriptStateEffect;
struct FQueuedStateTransition;
enum class EAresEquippableInput : uint8;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnScriptStateEnter, UScriptStateComponent*, EnteredState, UStateTransitionContext*, StateTransitionContext, float, StartTimeOffset);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnScriptStateExit, UScriptStateComponent*, ExitedState, UStateTransitionContext*, StateTransitionContext);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnScriptStateTick, UScriptStateComponent*, State, float, DeltaTimeSeconds);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnScriptStateHandleInputAction, UScriptStateComponent*, State, EAresEquippableInput, Input, EAresEquippableInputAction, InputAction, float, FrameDeltaTimeSeconds);

UCLASS()
class SHOOTERGAME_API UScriptStateComponent : public UEquippableStateComponent
{
    GENERATED_BODY()

public:

    UPROPERTY(EditDefaultsOnly)
    TArray<FEquippableStateBuffInfo> StateBuffs;

    UPROPERTY(BlueprintAssignable)
    FOnScriptStateEnter OnStateEnter;

    UPROPERTY(BlueprintAssignable)
    FOnScriptStateExit OnStateExit;

    UPROPERTY(BlueprintAssignable)
    FOnScriptStateTick OnStateTick;

protected:

    UPROPERTY(EditDefaultsOnly)
    TArray<FScriptStateEffectInfo> StateEffects;

    UPROPERTY()
    UStateComponent* ScriptNextState;

private:

    UPROPERTY()
    TWeakObjectPtr<UObject> CustomContext;

    UPROPERTY()
    TArray<FActiveScriptStateEffect> ActiveStateEffects;

    UPROPERTY()
    FQueuedStateTransition QueuedStateTransition;

    UPROPERTY(BlueprintAssignable)
    FOnScriptStateHandleInputAction OnStateHandleInputAction;

    UPROPERTY(Transient)
    UStateTransitionContext* CurrentContext;

    UPROPERTY(Transient)
    UStateTransitionContext* CachedContext;

public:

    void GoToNextState(float TimeUntilTransition);
    void GoToState(UStateComponent* NewState, float TimeUntilTransition);
    void GoToStateWithContext(UStateComponent* NewState, UStateTransitionContext* Context, float TimeUntilTransition);
    void OnSyncToAuthValues();
    void SetCurrentContext(UStateTransitionContext* NewContext);
    void SetCustomContext(UObject* NewContext);
    void SetDefaultNextState(UStateComponent* State);
    UStateTransitionContext* SetNewContext(TSubclassOf<UStateTransitionContext> ContextType);

    UStateTransitionContext* GetCurrentContext() const;
    UStateComponent* GetDefaultNextState() const;
};