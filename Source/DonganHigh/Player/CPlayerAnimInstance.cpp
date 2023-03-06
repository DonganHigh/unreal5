#include "CPlayerAnimInstance.h"
#include "Global.h"
#include "CPlayer.h"

void UCPlayerAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	Player = Cast<ACPlayer>(Owner);
	CheckNull(Player);
}

void UCPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}
