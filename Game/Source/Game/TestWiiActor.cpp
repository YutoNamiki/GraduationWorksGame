// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "TestWiiActor.h"

void on_state_change(wiimote& remote, state_change_flags changed, const wiimote_state& new_state);

float gSpeedYaw = 0.0f;
float gSpeedPitch = 0.0f;
float gSpeedRoll = 0.0f;

// Sets default values
ATestWiiActor::ATestWiiActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	remote.ChangedCallback = on_state_change;
	remote.CallbackTriggerFlags = (state_change_flags)(CONNECTED | CHANGED_ALL);
}

// Called when the game starts or when spawned
void ATestWiiActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATestWiiActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!remote.IsConnected())
	{
		UE_LOG(LogTemp, Warning, TEXT("Wiiremote is Connecting"));
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

	motionPlusYaw = gSpeedYaw;
	motionPlusPitch = gSpeedPitch;
	motionPlusRoll = gSpeedRoll;

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
}

void on_state_change(wiimote& remote, state_change_flags changed, const wiimote_state& new_state)
{
	// 接続されたら
	if (changed & CONNECTED)
	{
		if (new_state.ExtensionType != wiimote::BALANCE_BOARD)
		{
			if (new_state.bExtension)
				remote.SetReportType(wiimote::IN_BUTTONS_ACCEL_IR_EXT);	// no IR dots
			else
				remote.SetReportType(wiimote::IN_BUTTONS_ACCEL_IR);	// IR dots
		}
	}

	// モーションプラスの検出したら
	if (changed & MOTIONPLUS_DETECTED)                              
	{
		remote.EnableMotionPlus();
	}
	// 拡張コネクタにモーションプラスが接続されてたら
	else if (changed & MOTIONPLUS_EXTENSION_CONNECTED)
	{
		if (remote.MotionPlusEnabled())
			remote.EnableMotionPlus();
	}
	// モーションプラスが拡張コネクタから切断されたら
	else if (changed & MOTIONPLUS_EXTENSION_DISCONNECTED)
	{
		// 再びモーションプラスのデータを有効にする
		if (remote.MotionPlusConnected())
			remote.EnableMotionPlus();
	}
	// その他の拡張機器が接続されたら
	else if (changed & EXTENSION_CONNECTED)
	{
		if (!remote.IsBalanceBoard())
			remote.SetReportType(wiimote::IN_BUTTONS_ACCEL_EXT);
	}
	// その他の拡張機器が切断されたら
	else if (changed & EXTENSION_DISCONNECTED)
	{
		remote.SetReportType(wiimote::IN_BUTTONS_ACCEL_IR);
	}

	// 何らかの変化が起こったら
	if (changed & CHANGED_ALL)
	{
		// リフレッシュ
		remote.RefreshState();

		// モーションプラスの状態変化が起こったら
		if (changed & MOTIONPLUS_SPEED_CHANGED) {
			gSpeedYaw = remote.MotionPlus.Speed.Yaw;
			gSpeedPitch = remote.MotionPlus.Speed.Pitch;
			gSpeedRoll = remote.MotionPlus.Speed.Roll;
		}
	}
}