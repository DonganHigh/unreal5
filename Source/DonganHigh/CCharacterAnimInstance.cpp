#include "CCharacterAnimInstance.h"
#include "Global.h"
#include "GameFramework/Character.h"

void UCCharacterAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	Owner = Cast<ACharacter>(TryGetPawnOwner());
	CheckNull(Owner);
}

void UCCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	CheckNull(Owner);

	Speed = Owner->GetVelocity().Size2D();
	Direction = CalculateDirection(Owner->GetVelocity(), Owner->GetActorRotation());
}