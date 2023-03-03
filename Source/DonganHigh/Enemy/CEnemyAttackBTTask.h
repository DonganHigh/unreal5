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
	//틱 넣어서 스테이트가 idle시 성공반환

	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
