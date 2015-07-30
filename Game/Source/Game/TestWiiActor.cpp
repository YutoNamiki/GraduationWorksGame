// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "TestWiiActor.h"

void on_state_change(wiimote& remote, state_change_flags changed, const wiimote_state& new_state);

bool bConnected;
int gAgeCount;
FVector gAccel, gVelocity, gPosition;
float g_speed_yaw = 0.0f;
float g_speed_pitch = 0.0f;
float g_speed_roll = 0.0f;
// Sets default values
ATestWiiActor::ATestWiiActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bConnected = false;
	gAgeCount = 0;

	moveSpeed = 400.0f;

	gAccel = FVector(gAccel.ZeroVector);
	gVelocity = FVector(gVelocity.ZeroVector);
	gPosition = FVector(gPosition.ZeroVector);

	remote.ChangedCallback = on_state_change;
	remote.CallbackTriggerFlags = (state_change_flags)(CONNECTED | CHANGED_ALL);

}

// Called when the game starts or when spawned
void ATestWiiActor::BeginPlay()
{
	Super::BeginPlay();

	int count = 0;
	while (!bConnected)
	{
		while (!remote.Connect(wiimote::FIRST_AVAILABLE));
		if (remote.UniqueID == 0)
			remote.Disconnect();
		else
			bConnected = true;

		count++;
		if (count > 600)
			break;
	}
}

// Called every frame
void ATestWiiActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	accel = gAccel;
	motionPlusYaw = g_speed_yaw;
	motionPlusPitch = g_speed_pitch;
	motionPlusRoll = g_speed_roll;

	UE_LOG(LogTemp, Warning, TEXT("座標　        ：[pitch] %+2.3f [roll] %+2.3f [yaw] %+2.3f\n"), motionPlusPitch, motionPlusRoll, motionPlusYaw);
	if (remote.Button.B())
	{
		bPushAbutton = false;
		bPushBbutton = true;
		gAccel = FVector(gAccel.ZeroVector);
		gVelocity = FVector(gVelocity.ZeroVector);
	}
	else if (remote.Button.A())
	{
		bPushAbutton = true;
		bPushBbutton = false;
	}
	else
	{
		bPushAbutton = false;
		bPushBbutton = false;
	}

	if (remote.Button.Up())
		bPushUpButton = true;
	else if (remote.Button.Down())
		bPushDownButton = true;
	else
	{
		bPushUpButton = false;
		bPushDownButton = false;
	}
	if (remote.Button.Right())
		bPushRightButton = true;
	else if (remote.Button.Left())
		bPushLeftButton = true;
	else
	{
		bPushRightButton = false;
		bPushLeftButton = false;
	}

	gVelocity.Y += -gAccel.X * DeltaTime;
	gVelocity.Z += -gAccel.Y * DeltaTime;

	gPosition += gVelocity * moveSpeed * DeltaTime;
	
	velocity = gVelocity;
	position = gPosition;
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
		bool res = remote.EnableMotionPlus();
		while (!res)
		{
			if (remote.ExtensionType == wiimote_state::NONE)
			{
				res = remote.EnableMotionPlus();
			}
		}
		// 拡張コネクタにモーションプラスが接続されてたら
	}
	else if (changed & MOTIONPLUS_EXTENSION_CONNECTED) 
	{
		if (remote.MotionPlusEnabled())
			remote.EnableMotionPlus();
		// モーションプラスが拡張コネクタから切断されたら
	}
	else if (changed & MOTIONPLUS_EXTENSION_DISCONNECTED) 
	{
		// 再びモーションプラスのデータを有効にする
		if (remote.MotionPlusConnected())
			remote.EnableMotionPlus();
		// その他の拡張機器が接続されたら
	}
	else if (changed & EXTENSION_CONNECTED) 
	{
		if (!remote.IsBalanceBoard())
			remote.SetReportType(wiimote::IN_BUTTONS_ACCEL_EXT);
		// その他の拡張機器が切断されたら
	}
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
			g_speed_yaw = remote.MotionPlus.Speed.Yaw;
			g_speed_pitch = remote.MotionPlus.Speed.Pitch;
			g_speed_roll = remote.MotionPlus.Speed.Roll;
			/*UE_LOG(LogTemp, Warning, TEXT("座標　        ：[pitch] %+2.3f [roll] %+2.3f [yaw] %+2.3f\n"), g_speed_pitch, g_speed_roll, g_speed_yaw);*/
		}

		// モーションプラスの状態変化が起こったら
		if (changed & ACCEL_CHANGED)
		{
			//加速度
			float accelX = floor(remote.Acceleration.X * 10.0f) / 10.0f;
			float accelY = floor(remote.Acceleration.Y * 10.0f) / 10.0f;
			float accelZ = floor(remote.Acceleration.Z * 10.0f) / 10.0f;

			if (remote.Acceleration.Orientation.UpdateAge == 0)
			{
				gAgeCount++;
				gVelocity = gVelocity.ZeroVector;
			}

			if (gAgeCount == 2 && remote.Acceleration.Orientation.UpdateAge == 0)
			{
				gAccel = FVector(gAccel.ZeroVector);
				gVelocity = FVector(gVelocity.ZeroVector);
				gAgeCount = 0;
			}

			gAccel = FVector(accelX, accelY, accelZ);

			/*UE_LOG(LogTemp, Warning, TEXT("加速度センサー  ：[X] %+2.3f [Y] %+2.3f [Z] %+2.3f\n"), remote.Acceleration.X, remote.Acceleration.Y, remote.Acceleration.Z);
			UE_LOG(LogTemp, Warning, TEXT("加速度(値丸め後)：[X] %+2.3f [Y] %+2.3f [Z] %+2.3f\n"), gAccel.X, gAccel.Y, gAccel.Z);*/

			gAccel.X -= remote.Acceleration.Orientation.X;
			gAccel.Y -= remote.Acceleration.Orientation.Y;

			gAccel.X = floor(gAccel.X * 10.0f) / 10.0f;
			gAccel.Y = floor(gAccel.Y * 10.0f) / 10.0f;
			gAccel.X += 0.1f;
			gAccel.Y += 0.1f;

			/*UE_LOG(LogTemp, Warning, TEXT("加速度(-重力)   ：[X] %+2.3f [Y] %+2.3f [Z] %+2.3f\n"), gAccel.X, gAccel.Y, gAccel.Z);
			UE_LOG(LogTemp, Warning, TEXT(" "));
			UE_LOG(LogTemp, Warning, TEXT("回転度センサー  ：[X] %+2.3f [Y] %+2.3f [Z] %+2.3f\n"), remote.Acceleration.Orientation.X, remote.Acceleration.Orientation.Y, remote.Acceleration.Orientation.Z);
			UE_LOG(LogTemp, Warning, TEXT("回転          ：[Pitch]%+2.3f [Roll]%+2.3f\n"), remote.Acceleration.Orientation.Pitch, remote.Acceleration.Orientation.Roll);
			UE_LOG(LogTemp, Warning, TEXT(" "));
			UE_LOG(LogTemp, Warning, TEXT("速度　        ：[X] %+2.3f [Y] %+2.3f [Z] %+2.3f\n"), gVelocity.X, gVelocity.Y, gVelocity.Z);
			UE_LOG(LogTemp, Warning, TEXT("座標　        ：[X] %+2.3f [Y] %+2.3f [Z] %+2.3f\n"), gPosition.X, gPosition.Y, gPosition.Z);
			UE_LOG(LogTemp, Warning, TEXT("UpdateAge       :%d"), remote.Acceleration.Orientation.UpdateAge);
			UE_LOG(LogTemp, Warning, TEXT(" "));*/
			
		}
	}
}

void ATestWiiActor::PushArrowButton()
{
	if (bPushUpButton)
	{
		velocity.Z = 0.1f;
	}
	else if (bPushDownButton)
	{
		velocity.Z = -0.1f;
	}
	else
	{
		velocity.Z = 0.0f;
	}

	if (bPushRightButton)
	{
		velocity.Y = 0.1f;
	}
	else if (bPushLeftButton)
	{
		velocity.Y = -0.1f;
	}
	else
	{
		velocity.Y = 0.0f;
	}
}