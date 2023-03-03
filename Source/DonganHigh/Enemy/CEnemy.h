#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CEnemy.generated.h"

UCLASS()
class DONGANHIGH_API ACEnemy : public ACharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleDefaultsOnly, Category = "Component")
		class UCStateComponent* State;

public:
	ACEnemy();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	FORCEINLINE int GetZombieType() { return ZombieType; }

public:
	void Attack();

private:
	UAnimMontage* Attack01;
	UAnimMontage* Attack02;
	UAnimMontage* Attack03;

private:
	float Health;
	float MaxHealth;
	int ZombieType = -1;
};