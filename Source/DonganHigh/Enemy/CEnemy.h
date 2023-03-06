#pragma once

#include "CoreMinimal.h"
#include "CCharacter.h"
#include "CEnemy.generated.h"

UCLASS()
class DONGANHIGH_API ACEnemy : public ACCharacter
{
	GENERATED_BODY()

public:
	ACEnemy();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	FORCEINLINE int GetZombieType() { return ZombieType; }

public:
	void Attack() override;

private:
	UAnimMontage* Attack01;
	UAnimMontage* Attack02;
	UAnimMontage* Attack03;

private:
	int ZombieType = -1;
};