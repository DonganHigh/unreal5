#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CCharacterAnimInstance.generated.h"

UCLASS()
class DONGANHIGH_API UCCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character")
		float Speed;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character")
		float Direction;

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	class ACharacter* Owner;
};
