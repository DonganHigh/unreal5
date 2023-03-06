#include "CEnemyAnimInstance.h"
#include "Global.h"
#include "CEnemy.h"


void UCEnemyAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	
	Enemy = Cast<ACEnemy>(Owner);
	CheckNull(Enemy);

	ZombieType = Enemy->GetZombieType();
}

void UCEnemyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}