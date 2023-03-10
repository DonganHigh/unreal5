#include "CEnemyAttackBTTask.h"
#include "Global.h"
#include "CEnemy.h"
#include "CEnemyAIController.h"
#include "Components/CStateComponent.h"

#include "BehaviorTree/BlackboardComponent.h"

UCEnemyAttackBTTask::UCEnemyAttackBTTask()
{
	NodeName = TEXT("Attack");
	bNotifyTick = true;
}

EBTNodeResult::Type UCEnemyAttackBTTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	ACEnemy* ControllingEnemy = Cast<ACEnemy>(OwnerComp.GetAIOwner()->GetCharacter());
	if (ControllingEnemy == nullptr) return EBTNodeResult::Failed;
	
	ControllingEnemy->StopAnimMontage();
	ControllingEnemy->Attack();

	return EBTNodeResult::InProgress;
}

void UCEnemyAttackBTTask::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	ACEnemy* ControllingEnemy = Cast<ACEnemy>(OwnerComp.GetAIOwner()->GetCharacter());
	if (ControllingEnemy == nullptr) FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
	
	UCStateComponent* state = CHelpers::GetComponent<UCStateComponent>(ControllingEnemy);
	if (state == nullptr) FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
	
	if (state->IsIdleState()) FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);		
}