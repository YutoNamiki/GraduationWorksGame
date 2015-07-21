// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Game.h"
#include "GameGameMode.h"
#include "GameHUD.h"
#include "GameCharacter.h"

AGameGameMode::AGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGameHUD::StaticClass();
}
