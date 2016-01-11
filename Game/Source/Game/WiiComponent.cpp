// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "WiiComponent.h"

void onStateChange(wiimote& remote, state_change_flags changed, const wiimote_state& new_state);

float SpeedYaw = 0.0f;
float SpeedPitch = 0.0f;
float SpeedRoll = 0.0f;

float NunchukAccelX = 0.0f;
float NunchukAccelY = 0.0f;
float NunchukAccelZ = 0.0f;

bool NunchukZ = 0;
bool NunchukC = 0;

// Sets default values for this component's properties
UWiiComponent::UWiiComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	remote.ChangedCallback = onStateChange;
	remote.CallbackTriggerFlags = (state_change_flags)(CONNECTED | EXTENSION_CHANGED | MOTIONPLUS_CHANGED);
}


// Called when the game starts
void UWiiComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// ...
	
}


// Called every frame
void UWiiComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
	if (tryCount > 10)
		return;
	if (!remote.IsConnected())
	{
		tryCount++;
		UE_LOG(LogTemp, Warning, TEXT("%d:Wiiremote is Connecting"), tryCount);
		if (!remote.Connect(wiimote::FIRST_AVAILABLE))
		{
			UE_LOG(LogTemp, Warning, TEXT("Wiiremote connect is failed"));
			if (remote.UniqueID == 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Invalid wiiremote's uniqueID"));
				remote.Disconnect();
			}
			UE_LOG(LogTemp, Warning, TEXT("Wiiremote connect Error"));
		}
		else
			UE_LOG(LogTemp, Warning, TEXT("Wiiremote is connected"));
		return;
	}

	switch (remote.ExtensionType)
	{
		case wiimote_state::NONE:
		{
			UE_LOG(LogTemp, Warning, TEXT("none"));
		}
		case wiimote_state::NUNCHUK:
		{
			UE_LOG(LogTemp, Warning, TEXT("nunchuk"));
			nunchukAccelX = NunchukAccelX;
			nunchukAccelY = NunchukAccelY;
			nunchukAccelZ = NunchukAccelZ;
		}
		case wiimote_state::MOTION_PLUS:
		{
			UE_LOG(LogTemp, Warning, TEXT("motionplus"));
			motionPlusYaw = SpeedYaw;
			motionPlusPitch = SpeedPitch;
			motionPlusRoll = SpeedRoll;
		}
	}

	if (remote.NunchukConnected())
	{
		UE_LOG(LogTemp, Warning, TEXT("nunchuk connected"));
	}

	if (remote.MotionPlusConnected())
	{
		UE_LOG(LogTemp, Warning, TEXT("motionplus connected"));
		if (remote.MotionPlusEnabled())
		{
			UE_LOG(LogTemp, Warning, TEXT("motionplus enable"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("motionplus not enable"));
		}
	}

	if (remote.Button.A())
		bPushAbutton = true;
	else
		bPushAbutton = false;

	if (remote.Button.B())
		bPushBbutton = true;
	else
		bPushBbutton = false;

	if (remote.Button.Up())
		bPushUpButton = true;
	else
		bPushUpButton = false;

	if (remote.Button.Down())
		bPushDownButton = true;
	else
		bPushDownButton = false;

	if (remote.Button.Right())
		bPushRightButton = true;
	else
		bPushRightButton = false;

	if (remote.Button.Left())
		bPushLeftButton = true;
	else
		bPushLeftButton = false;

	if (remote.Button.Home())
		bPushHomeButton = true;
	else
		bPushHomeButton = false;

	if (remote.Button.Plus())
		bPushPlusButton = true;
	else
		bPushPlusButton = false;

	if (remote.Button.Minus())
		bPushMinusButton = true;
	else
		bPushMinusButton = false;

	if (remote.Button.One())
		bPushOneButton = true;
	else
		bPushOneButton = false;

	if (remote.Button.Two())
		bPushTwoButton = true;
	else
		bPushTwoButton = false;

	bPushNunchukButtonZ = NunchukZ;
	bPushNunchukButtonC = NunchukC;
}

void onStateChange(wiimote& remote, state_change_flags changed, const wiimote_state& new_state)
{
	// we use this callback to set report types etc. to respond to key events
	//  (like the wiimote connecting or extensions (dis)connecting).

	// NOTE: don't access the public state from the 'remote' object here, as it will
	//		  be out-of-date (it's only updated via RefreshState() calls, and these
	//		  are reserved for the main application so it can be sure the values
	//		  stay consistent between calls).  Instead query 'new_state' only.

	// the wiimote just connected
	if (changed & CONNECTED)
	{
		// ask the wiimote to report everything (using the 'non-continous updates'
		//  default mode - updates will be frequent anyway due to the acceleration/IR
		//  values changing):

		// note1: you don't need to set a report type for Balance Boards - the
		//		   library does it automatically.

		// note2: for wiimotes, the report mode that includes the extension data
		//		   unfortunately only reports the 'BASIC' IR info (ie. no dot sizes),
		//		   so let's choose the best mode based on the extension status:
		if (new_state.ExtensionType != wiimote::BALANCE_BOARD)
		{
			if (new_state.bExtension)
			{
				UE_LOG(LogTemp, Warning, TEXT("all"));
				remote.SetReportType(wiimote::IN_BUTTONS_ACCEL_IR_EXT); // no IR dots
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("not all"));
				remote.SetReportType(wiimote::IN_BUTTONS_ACCEL_IR);		//    IR dots
			}
		}
	}
	// a MotionPlus was detected
	if (changed & MOTIONPLUS_DETECTED)
	{
		// enable it if there isn't a normal extension plugged into it
		// (MotionPlus devices don't report like normal extensions until
		//  enabled - and then, other extensions attached to it will no longer be
		//  reported (so disable the M+ when you want to access them again).
		if (remote.ExtensionType == wiimote_state::NONE) {
			bool res = remote.EnableMotionPlus();
			_ASSERT(res);
		}
	}
	// an extension is connected to the MotionPlus
	else if (changed & MOTIONPLUS_EXTENSION_CONNECTED)
	{
		// We can't read it if the MotionPlus is currently enabled, so disable it:
		if (remote.MotionPlusEnabled())
			remote.DisableMotionPlus();
	}
	// an extension disconnected from the MotionPlus
	else if (changed & MOTIONPLUS_EXTENSION_DISCONNECTED)
	{
		// enable the MotionPlus data again:
		if (remote.MotionPlusConnected())
			remote.EnableMotionPlus();
	}
	// another extension was just connected:
	else if (changed & EXTENSION_CONNECTED)
	{
		// switch to a report mode that includes the extension data (we will
		//  loose the IR dot sizes)
		// note: there is no need to set report types for a Balance Board.
		if (!remote.IsBalanceBoard())
			remote.SetReportType(wiimote::IN_BUTTONS_ACCEL_IR_EXT);
	}
	// extension was just disconnected:
	else if (changed & EXTENSION_DISCONNECTED)
	{
		// use a non-extension report mode (this gives us back the IR dot sizes)
		remote.SetReportType(wiimote::IN_BUTTONS_ACCEL_IR);
	}


	// 何らかの変化が起こったら
	if (changed & CHANGED_ALL)
	{
		// リフレッシュ
		remote.RefreshState();

		// モーションプラスの状態変化が起こったら
		if (changed & MOTIONPLUS_SPEED_CHANGED) {
			UE_LOG(LogTemp, Warning, TEXT("motionplus accel"));
			SpeedYaw = remote.MotionPlus.Speed.Yaw;
			SpeedPitch = remote.MotionPlus.Speed.Pitch;
			SpeedRoll = remote.MotionPlus.Speed.Roll;
		}

		if (changed & BUTTONS_CHANGED)
		{
			UE_LOG(LogTemp, Warning, TEXT("wiiremote buttonaaaaaaaaaaaaaaaaaaaaaaaaa"));
		}

		if (changed & NUNCHUK_ACCEL_CHANGED)
		{
			UE_LOG(LogTemp, Warning, TEXT("nunchuk accel"));
			NunchukAccelX = remote.Nunchuk.Acceleration.X;
			NunchukAccelY = remote.Nunchuk.Acceleration.Y;
			NunchukAccelZ = remote.Nunchuk.Acceleration.Z;
		}

		if (changed & NUNCHUK_BUTTONS_CHANGED)
		{
			UE_LOG(LogTemp, Warning, TEXT("nunchuk button"));
			NunchukZ = remote.Nunchuk.Z;
			NunchukC = remote.Nunchuk.C;
		}
	}
}