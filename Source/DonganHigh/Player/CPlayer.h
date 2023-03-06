#pragma once

#include "CoreMinimal.h"
#include "CCharacter.h"
#include "CPlayer.generated.h"

UCLASS()
class DONGANHIGH_API ACPlayer : public ACCharacter
{
	GENERATED_BODY()

public:
	ACPlayer();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringArmComponent;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComponent; }
	FORCEINLINE class USpringArmComponent* GetSpringArmComponent() const { return SpringArmComponent; }

public:
	void Attack() override;

};
