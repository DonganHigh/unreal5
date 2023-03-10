#include "CPlayerAnimInstance.h"
#include "Global.h"
#include "CPlayer.h"

void UCPlayerAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	Player = Cast<ACPlayer>(Owner);
	CheckNull(Player);


	Weapon = CHelpers::GetComponent<UCWeaponComponent>(Player);

	if (!!Weapon)
		Weapon->OnWeaponTypeChange.AddDynamic(this, &UCPlayerAnimInstance::OnWeaponTypeChanged);
}

void UCPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}

void UCPlayerAnimInstance::OnWeaponTypeChanged(EWeaponType InPrevType, EWeaponType InNewType)
{
	WeaponType = InNewType;
}