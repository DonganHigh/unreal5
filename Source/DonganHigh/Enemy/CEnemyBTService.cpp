#include "CEnemyBTService.h"
#include "Global.h"
#include "CEnemyAIController.h"
#include "CEnemy.h"

UCEnemyBTService::UCEnemyBTService()
{
	NodeName = TEXT("Detect");
	Interval = 1.0f;
}

void UCEnemyBTService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	CLog::Print("Check", 1);

	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();		//ÀÌ°Ô null·Î ÀâÈû
	CheckNull(ControllingPawn);

	UWorld* World = ControllingPawn->GetWorld();
	CheckNull(World);
	CLog::Print("Check3", 3);

	FVector Center = ControllingPawn->GetActorLocation();
	float DetectRadius = 60.0f;

	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, ControllingPawn);
	bool bResult = World->OverlapMultiByChannel(OverlapResults,	Center,	FQuat::Identity, ECollisionChannel::ECC_Pawn, FCollisionShape::MakeSphere(DetectRadius), CollisionQueryParam);

	if (bResult)
	{
		for (FOverlapResult OverlapResult : OverlapResults)
		{
			ACharacter* Character = Cast<ACharacter>(OverlapResult.GetActor());
			if (Character->GetController()->IsPlayerController())
			{
				CLog::Print("Player Check", 3);
			}
		}
	}
	DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Red, true, 0.2f);
} 