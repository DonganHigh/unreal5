#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "CEnemyAttackBTTask.generated.h"

UCLASS()
class DONGANHIGH_API UCEnemyAttackBTTask : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UCEnemyAttackBTTask();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
