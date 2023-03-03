#include "CEnemyBTService.h"
#include "Global.h"
#include "CEnemyAIController.h"
#include "CEnemy.h"
#include "BehaviorTree/BlackboardComponent.h"

UCEnemyBTService::UCEnemyBTService()
{
	NodeName = TEXT("Detect");
	Interval = 1.0f;
}

void UCEnemyBTService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	float DistanceToPlayer = 0.0f;

	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetCharacter();
	CheckNull(ControllingPawn);

	UWorld* World = ControllingPawn->GetWorld();
	CheckNull(World);

	FVector Center = ControllingPawn->GetActorLocation();
	float DetectRadius = 600.0f;
	//DrawDebugSphere(World, Center, DetectRadius, 32, FColor::Red, true, 1.0f);

	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, ControllingPawn);
	bool bResult = World->OverlapMultiByChannel(OverlapResults,	Center,	FQuat::Identity, ECollisionChannel::ECC_GameTraceChannel1, FCollisionShape::MakeSphere(DetectRadius), CollisionQueryParam);

	if (bResult)
	{
		for (FOverlapResult OverlapResult : OverlapResults)
		{
			ACharacter* Character = Cast<ACharacter>(OverlapResult.GetActor());
			CheckNull(Character);
			
			if (Character->GetController()->IsPlayerController())
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(ACEnemyAIController::Key_TargetActor, Character);
				DistanceToPlayer = ControllingPawn->GetDistanceTo(Character);
			}
		}
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(ACEnemyAIController::Key_TargetActor, nullptr);
	}

	if (OwnerComp.GetBlackboardComponent()->GetValueAsObject(ACEnemyAIController::Key_TargetActor) == nullptr)
	{
		AIBehavior = EAIBehavior::Patrol;
	}
	else
	{
		if (DistanceToPlayer < 150.0f)
		{
			AIBehavior = EAIBehavior::Attack;
		}
		else
		{
			AIBehavior = EAIBehavior::Approach;
		}
		
	}

	OwnerComp.GetBlackboardComponent()->SetValueAsEnum(ACEnemyAIController::Key_AIBehavior, (uint8)AIBehavior);
}