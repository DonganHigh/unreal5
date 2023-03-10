#include "CPlayer.h"
#include "Global.h"
#include "CPlayerAnimInstance.h"
#include "Components/CWeaponComponent.h"
#include "Components/CStateComponent.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"

ACPlayer::ACPlayer()
{
	USkeletalMesh* mesh;
	CHelpers::GetAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny'");

	GetMesh()->SetSkeletalMesh(mesh);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	GetMesh()->SetCollisionProfileName(TEXT("Player"));

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->SetUsingAbsoluteRotation(true);
	SpringArmComponent->TargetArmLength = 800.f;
	SpringArmComponent->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	SpringArmComponent->bDoCollisionTest = false;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;

	TSubclassOf<UCPlayerAnimInstance> animInstance;
	CHelpers::GetClass<UCPlayerAnimInstance>(&animInstance, "AnimBlueprint'/Game/Characters/Player/ABP_Player.ABP_Player_C'");
	GetMesh()->SetAnimClass(animInstance);

	CHelpers::CreateActorComponent<UCWeaponComponent>(this, &Weapon, "Weapon");
}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();

	GetCharacterMovement()->MaxWalkSpeed = 400.0f;
}

void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if (!Weapon->IsUnarmedMode())
	//{
		LookAtCursor();
	//}
	
}

void ACPlayer::LookAtCursor()
{
	FHitResult hitResult;
	bool bResult = (UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHitResultUnderCursor(ECC_Visibility, true, hitResult));

	if (bResult)
	{
		SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), FVector(hitResult.ImpactPoint.X, hitResult.ImpactPoint.Y, GetActorLocation().Z)));
	}	
}

void ACPlayer::WheelZoom(float AxisValue)
{
	//SpringArmComponent->TargetArmLength
}