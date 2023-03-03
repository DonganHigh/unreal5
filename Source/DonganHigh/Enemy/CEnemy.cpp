#include "CEnemy.h"
#include "Global.h"
#include "CEnemyAIController.h"
#include "CEnemyAnimInstance.h"
#include "Components/CStateComponent.h"

#include "GameFramework/CharacterMovementComponent.h"

ACEnemy::ACEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	if (ZombieType == -1)
	{
		ZombieType = FMath::RandRange(0, 2);
	}

	CHelpers::CreateActorComponent<UCStateComponent>(this, &State, "State");

	USkeletalMesh* mesh;
	CHelpers::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Characters/Mannequin_UE4/Meshes/SK_Mannequin.SK_Mannequin'");

	//switch (ZombieType)
	//{
	//case 0: 
	//	CHelpers::GetAsset<USkeletalMesh>(&mesh, "");
	//	break;
	//
	//case 1:
	//	CHelpers::GetAsset<USkeletalMesh>(&mesh, "");
	//	break;
	//
	//case 2:
	//	CHelpers::GetAsset<USkeletalMesh>(&mesh, "");
	//	break;
	//}

	GetMesh()->SetSkeletalMesh(mesh);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0)); 

	TSubclassOf<UCEnemyAnimInstance> animInstance;
	CHelpers::GetClass<UCEnemyAnimInstance>(&animInstance, "AnimBlueprint'/Game/Characters/Enemy/ABP_Enemy.ABP_Enemy_C'");
	GetMesh()->SetAnimClass(animInstance);

	CHelpers::GetAsset<UAnimMontage>(&Attack01, "AnimMontage'/Game/Characters/Enemy/Animation/Attacks/Zombie_Attack_01_Montage.Zombie_Attack_01_Montage'");
	CHelpers::GetAsset<UAnimMontage>(&Attack02, "AnimMontage'/Game/Characters/Enemy/Animation/Attacks/Zombie_Attack_02_Montage.Zombie_Attack_02_Montage'");
	CHelpers::GetAsset<UAnimMontage>(&Attack03, "AnimMontage'/Game/Characters/Enemy/Animation/Attacks/Zombie_Attack_03_Montage.Zombie_Attack_03_Montage'");

	AIControllerClass = ACEnemyAIController::StaticClass();
}

void ACEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	Health = MaxHealth;
	GetCharacterMovement()->MaxWalkSpeed = 200.0f;

}

void ACEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACEnemy::Attack()
{
	State->SetAttackState();

	PlayAnimMontage(Attack01);
}