#include "CFindPatrolPositionBTTask.h"
#include "Global.h"
#include "CEnemy.h"
#include "CEnemyAIController.h"
#include "Components/CStateComponent.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"

UCFindPatrolPositionBTTask::UCFindPatrolPositionBTTask()
{
	NodeName = TEXT("FindPatrolPosition");
}

EBTNodeResult::Type UCFindPatrolPositionBTTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ACEnemy* ControllingEnemy = Cast<ACEnemy>(OwnerComp.GetAIOwner()->GetCharacter());
	if (ControllingEnemy == nullptr) return EBTNodeResult::Failed;

	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(ControllingEnemy->GetWorld());
	if (nullptr == NavSystem) return EBTNodeResult::Failed;

	//UCStateComponent* state = CHelpers::GetComponent<UCStateComponent>(ControllingEnemy);
	//if (state == nullptr) return EBTNodeResult::Failed;

	//if(!state->IsIdleState()) return EBTNodeResult::Failed;

	FVector Origin = (Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(ACEnemyAIController::Key_SelfActor)))->GetActorLocation();
	
	FNavLocation NextPatrol;
	if (NavSystem->GetRandomPointInNavigableRadius(Origin, 300.0f, NextPatrol))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(ACEnemyAIController::Key_PatrolPosition, NextPatrol.Location);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
