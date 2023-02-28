#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CEnemy.generated.h"

UCLASS()
class DONGANHIGH_API ACEnemy : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		class UBehaviorTree* BehaviorTree;
public:
	ACEnemy();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	class UBehaviorTree* GetBehaviorTree(){ return BehaviorTree; }

private:
	float Health;
	float MaxHealth;

};