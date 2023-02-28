#include "CEnemyAIController.h"
#include "Global.h"
#include "CEnemy.h"


ACEnemyAIController::ACEnemyAIController()
{
}

void ACEnemyAIController::OnPossess(APawn* InPawn)
{
	CEnemy = Cast<ACEnemy>(InPawn);
	CheckNull(CEnemy);

	RunBehaviorTree(CEnemy->GetBehaviorTree());
}