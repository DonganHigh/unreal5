#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPlayerController.generated.h"

UCLASS()
class DONGANHIGH_API ACPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ACPlayerController();

protected:
	virtual void OnPossess(APawn* aPawn) override;
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	

private:
	void MoveForward(float Value);
	void MoveRight(float Value);

private:
	class ACPlayer* Player;
	class UCWeaponComponent* Weapon;
};
