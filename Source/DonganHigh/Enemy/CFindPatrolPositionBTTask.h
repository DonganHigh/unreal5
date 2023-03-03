#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "CFindPatrolPositionBTTask.generated.h"

UCLASS()
class DONGANHIGH_API UCFindPatrolPositionBTTask : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UCFindPatrolPositionBTTask();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
