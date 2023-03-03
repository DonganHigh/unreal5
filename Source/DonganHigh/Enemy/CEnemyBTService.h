#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "CEnemyBTService.generated.h"

UENUM(BlueprintType)
enum class EAIBehavior : uint8
{
	Wait UMETA(DisplayName = "Wait"), 
	Patrol UMETA(DisplayName = "Patrol"), 
	Approach UMETA(DisplayName = "Approach"), 
	Attack UMETA(DisplayName = "Attack"), 
	Hitted UMETA(DisplayName = "Hitted"),
};

UCLASS()
class DONGANHIGH_API UCEnemyBTService : public UBTService
{
	GENERATED_BODY()
public:
	UCEnemyBTService();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

public:
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector Target;

private:
	EAIBehavior AIBehavior = EAIBehavior::Wait;
};
