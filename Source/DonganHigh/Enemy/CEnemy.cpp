#include "CEnemy.h"
#include "Global.h"
#include "CEnemyAIController.h"
#include "GameFramework/CharacterMovementComponent.h"

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