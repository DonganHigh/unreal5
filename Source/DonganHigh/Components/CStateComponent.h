#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStateComponent.generated.h"

enum class EState : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	Attack UMETA(DisplayName = "Attack"),
	Hitted UMETA(DisplayName = "Hitted"),
	Dead UMETA(DisplayName = "Dead"),
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DONGANHIGH_API UCStateComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	EState State = EState::Idle;

public:
	FORCEINLINE bool IsIdleState() { return State == EState::Idle ? true : false; }
	FORCEINLINE bool IsAttackState() { return State == EState::Attack ? true : false; }
	FORCEINLINE bool IsHittedState() { return State == EState::Hitted ? true : false; }
	FORCEINLINE bool IsDeadState() { return State == EState::Dead ? true : false; }

	FORCEINLINE void SetIdleState() { State = EState::Idle; }
	FORCEINLINE void SetAttackState() { State = EState::Attack; }
	FORCEINLINE void SetHittedState() { State = EState::Hitted; }
	FORCEINLINE void SetDeadState() { State = EState::Dead; }
};
