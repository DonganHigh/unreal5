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

private:
	class ACEnemy* CEnemy;
};
