#include "CFindPatrolPositionBTTask.h"
#include "CEnemyAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"

UCFindPatrolPositionBTTask::UCFindPatrolPositionBTTask()
{
	NodeName = TEXT("FindPatrolPosition");
}

EBTNodeResult::Type UCFindPatrolPositionBTTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn) return EBTNodeResult::Failed;

	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(ControllingPawn->GetWorld());
	if (nullptr == NavSystem) return EBTNodeResult::Failed;

	FVector Origin = (Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(ACEnemyAIController::Key_SelfActor)))->GetActorLocation();
	
	FNavLocation NextPatrol;
	if (NavSystem->GetRandomPointInNavigableRadius(Origin, 300.0f, NextPatrol))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(ACEnemyAIController::Key_PatrolPosition, NextPatrol.Location);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
