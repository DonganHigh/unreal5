#include "CEnemy.h"
#include "Global.h"
#include "CEnemyAIController.h"

#include "BehaviorTree/BehaviorTree.h"

ACEnemy::ACEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	USkeletalMesh* mesh;
	CHelpers::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny'");
	GetMesh()->SetSkeletalMesh(mesh);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	//TSubclassOf<UCPlayerAnimInstance> animInstance;
	//CHelpers::GetClass<UCPlayerAnimInstance>(&animInstance, "_C'");
	//GetMesh()->SetAnimClass(animInstance);

	CHelpers::GetClass<AController>(&AIControllerClass, "Class'/Script/DonganHigh.CEnemyAIController_C'");

	CHelpers::GetBTObject<UBehaviorTree>(&BehaviorTree, "BehaviorTree'/Game/Characters/Enemy/BPEnemyBehaviorTree.BPEnemyBehaviorTree'");
}

void ACEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	Health = MaxHealth;

}

void ACEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}