#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CWeaponComponent.generated.h"


UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Pistol, AR4, Max,
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWeaponTypeChanged, EWeaponType, InPrevType, EWeaponType, InNewType);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DONGANHIGH_API UCWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCWeaponComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	FORCEINLINE bool IsPistolMode() { return Type == EWeaponType::Pistol; }
	FORCEINLINE bool IsAR4Mode() { return Type == EWeaponType::AR4; }
	FORCEINLINE bool IsUnarmedMode() { return Type == EWeaponType::Max; }

private:
	UPROPERTY(EditAnywhere, Category = "Weapon")
		TArray<TSubclassOf<class ACWeapon>> WeaponClasses;
	
public:
	void Attack();

public:
	FWeaponTypeChanged OnWeaponTypeChange;

private:
	EWeaponType Type = EWeaponType::Max;
};
