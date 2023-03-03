#pragma once

#include "CoreMinimal.h"
#include "../CCharacterAnimInstance.h"
#include "CEnemyAnimInstance.generated.h"

UCLASS()
class DONGANHIGH_API UCEnemyAnimInstance : public UCCharacterAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Enemy")
		int ZombieType = 0;
public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	class ACEnemy* Enemy;
};
