#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "CEnemyBTService.generated.h"

UCLASS()
class DONGANHIGH_API UCEnemyBTService : public UBTService
{
	GENERATED_BODY()
public:
	UCEnemyBTService();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

public:
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector Target;

};
