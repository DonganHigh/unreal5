#include "CPlayerController.h"
#include "Global.h"
#include "CPlayer.h"
#include "Components/CWeaponComponent.h"

ACPlayerController::ACPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void ACPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	Player = Cast<ACPlayer>(GetCharacter());
	CheckNull(Player);
	
	Weapon = CHelpers::GetComponent<UCWeaponComponent>(Player);
	CheckNull(Weapon);

	SetupInputComponent();
}

void ACPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void ACPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("Key_W/S", this, &ACPlayerController::MoveForward);
	InputComponent->BindAxis("Key_A/D", this, &ACPlayerController::MoveRight);
	CheckNull(Player);
	InputComponent->BindAxis("Mouse_Wheel", Player, &ACPlayer::WheelZoom);
	CheckNull(Weapon);
	InputComponent->BindAction("Mouse_Left", IE_Pressed, Weapon, &UCWeaponComponent::Attack);
}

void ACPlayerController::MoveForward(float AxisValue)
{
	FVector Direction = FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::X);
	GetCharacter()->AddMovementInput(Direction, AxisValue);
}

void ACPlayerController::MoveRight(float AxisValue)
{
	FVector Direction = FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::Y);
	GetCharacter()->AddMovementInput(Direction, AxisValue);
}