#pragma once

#include "CoreMinimal.h"
#include "CCharacterAnimInstance.h"
#include "Components/CWeaponComponent.h"
#include "CPlayerAnimInstance.generated.h"

UCLASS()
class DONGANHIGH_API UCPlayerAnimInstance : public UCCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Weapons")
		EWeaponType WeaponType = EWeaponType::Max;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Guns")
		bool Firing;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Guns")
		bool UseIK;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Weapons")
		FVector LeftHandLocation = FVector(-30, 15.5f, 4);

private:
	UFUNCTION()
		void OnWeaponTypeChanged(EWeaponType InPrevType, EWeaponType InNewType);

protected:
	class ACPlayer* Player;
	class UCWeaponComponent* Weapon;
};
