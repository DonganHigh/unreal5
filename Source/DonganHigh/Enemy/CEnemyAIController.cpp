#include "CEnemyAIController.h"
#include "Global.h"
#include "CEnemy.h"

#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTree.h"

const FName ACEnemyAIController::Key_SelfActor(TEXT("SelfActor"));
const FName ACEnemyAIController::Key_TargetActor(TEXT("TargetActor"));

ACEnemyAIController::ACEnemyAIController()
{
	CHelpers::GetBTObject<UBlackboardData>(&BlackBoardData, "BlackboardData'/Game/Characters/Enemy/BPEnemyBlackboardData.BPEnemyBlackboardData'");
	CHelpers::GetBTObject<UBehaviorTree>(&BehaviorTree, "BehaviorTree'/Game/Characters/Enemy/BPEnemyBehaviorTree.BPEnemyBehaviorTree'");
}

void ACEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	UBlackboardComponent* BlackboardComp = Blackboard;

	if (UseBlackboard(BlackBoardData, BlackboardComp))
	{
		RunBehaviorTree(BehaviorTree);
	}
}