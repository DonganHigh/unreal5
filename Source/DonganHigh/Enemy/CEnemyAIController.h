#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CEnemyAIController.generated.h"

UCLASS()
class DONGANHIGH_API ACEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:
	ACEnemyAIController();
	virtual void OnPossess(APawn* InPawn) override;

public:
	static const FName Key_SelfActor;
	static const FName Key_TargetActor;
	static const FName Key_AIBehavior;
	static const FName Key_PatrolPosition;

private:
	UPROPERTY(EditAnywhere)
		class UBlackboardData* BlackBoardData;

	UPROPERTY(EditAnywhere)
		class UBehaviorTree* BehaviorTree;

};
