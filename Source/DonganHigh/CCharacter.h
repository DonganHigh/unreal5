#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CCharacter.generated.h"

UCLASS()
class DONGANHIGH_API ACCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleDefaultsOnly, Category = "Component")
		class UCStateComponent* State;

public:
	ACCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	float Health;
	float MaxHealth;

};
