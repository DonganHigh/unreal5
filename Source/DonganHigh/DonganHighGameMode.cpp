// Copyright Epic Games, Inc. All Rights Reserved.

#include "DonganHighGameMode.h"
#include "Global.h"
//#include "DonganHighPlayerController.h"
//#include "DonganHighCharacter.h"
#include "Player/CPlayerController.h"
#include "Player/CPlayer.h"
#include "UObject/ConstructorHelpers.h"

ADonganHighGameMode::ADonganHighGameMode()
{
	//PlayerControllerClass = ADonganHighPlayerController::StaticClass();
	
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	//if (PlayerPawnBPClass.Class != nullptr)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class;
	//}
	//
	//static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	//if(PlayerControllerBPClass.Class != NULL)
	//{
	//	PlayerControllerClass = PlayerControllerBPClass.Class;
	//}

	CHelpers::GetClass<APawn>(&DefaultPawnClass, "Blueprint'/Game/Characters/Player/BPPlayer.BPPlayer_C'");
	PlayerControllerClass = ACPlayerController::StaticClass();
}