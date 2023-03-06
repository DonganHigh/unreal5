#include "CPlayerController.h"
#include "Global.h"
#include "CPlayer.h"

ACPlayerController::ACPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
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