#pragma once

#include "CoreMinimal.h"
#include "CCharacterAnimInstance.h"
#include "CPlayerAnimInstance.generated.h"

UCLASS()
class DONGANHIGH_API UCPlayerAnimInstance : public UCCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	class ACPlayer* Player;
};
