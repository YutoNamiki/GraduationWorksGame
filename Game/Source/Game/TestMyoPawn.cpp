// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "TestMyoPawn.h"

// Sets default values
ATestMyoPawn::ATestMyoPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ATestMyoPawn::BeginPlay()
{
	Super::BeginPlay();

	vibrateShortTime = 0;
	vibrateMediumTime = 0;
	vibrateLongTime = 0;

	bDoVibrateShort = false;
	bDoVibrateMedium = false;
	bDoVibrateLong = false;
}

// Called every frame
void ATestMyoPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (bDoVibrateShort)
	{
		vibrateShortTime++;
		if (vibrateShortTime >= VIBRATE_SHORT_TIME)
		{
			vibrateShortTime = 0;
			bDoVibrateShort = false;
		}
	}

	if (bDoVibrateMedium)
	{
		vibrateMediumTime++;
		if (vibrateMediumTime >= VIBRATE_MEDIUM_TIME)
		{
			vibrateMediumTime = 0;
			bDoVibrateMedium = false;
		}
	}

	if (bDoVibrateLong)
	{
		vibrateLongTime++;
		if (vibrateLongTime >= VIBRATE_LONG_TIME)
		{
			vibrateLongTime = 0;
			bDoVibrateLong = false;
		}
	}
}

// Called to bind functionality to input
void ATestMyoPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}

void ATestMyoPawn::MyoShortVibrate()
{
	if (!bDoVibrateShort)
	{
		bDoVibrateShort = true;
		IMyoPlugin::Get().VibrateDevice(1, MYO_VIBRATION_SHORT);
	}
}

void ATestMyoPawn::MyoMediumVibrate()
{
	if (!bDoVibrateMedium)
	{
		bDoVibrateMedium = true;
		IMyoPlugin::Get().VibrateDevice(1, MYO_VIBRATION_MEDIUM);
	}
}

void ATestMyoPawn::MyoLongVibrate()
{
	if (!bDoVibrateLong)
	{
		bDoVibrateLong = true;
		IMyoPlugin::Get().VibrateDevice(1, MYO_VIBRATION_LONG);
	}
}