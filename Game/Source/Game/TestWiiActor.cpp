// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "TestWiiActor.h"

void on_state_change(wiimote& remote, state_change_flags changed, const wiimote_state& new_state);

bool bConnected;
int gAgeCount;
FVector gAccel, gVelocity, gPosition;

// Sets default values
ATestWiiActor::ATestWiiActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bConnected = false;
	gAgeCount = 0;

	moveSpeed = 75.0f;

	gAccel = FVector(gAccel.ZeroVector);
	gVelocity = FVector(gVelocity.ZeroVector);
	gPosition = FVector(gPosition.ZeroVector);

	remote.ChangedCallback = on_state_change;
	remote.CallbackTriggerFlags = (state_change_flags)(CONNECTED | ACCEL_CHANGED);

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
void ATestWiiActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (remote.Button.B())
	{
		gAccel = FVector(gAccel.ZeroVector);
		gVelocity = FVector(gVelocity.ZeroVector);
	}

	gVelocity.Y += -gAccel.X * DeltaTime;
	/*if (gVelocity.Y > 0.01f)
	gVelocity.Y = 10.0f;
	else if (gVelocity.Y < -0.01f)
	gVelocity.Y = -10.0f;*/

	gVelocity.Z += -gAccel.Y * DeltaTime;
	/*if (gVelocity.Z > 0.03f)
	gVelocity.Z= 10.0f;
	else if (gVelocity.Z < -0.03f)
	gVelocity.Z = -10.0f;*/

	gPosition += gVelocity * moveSpeed * DeltaTime;

	if (remote.Button.A())
	{
		gAccel = FVector(gAccel.ZeroVector);
		gVelocity = FVector(gVelocity.ZeroVector);
		gPosition = FVector(gPosition.ZeroVector);
		gPosition.Y = 0.0f;
		gPosition.Z = 0.0f;
	}

	SetActorLocation(gPosition);
}

void on_state_change(wiimote& remote, state_change_flags changed, const wiimote_state& new_state)
{
	// �ڑ����ꂽ��
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

	// ���[�V�����v���X�̌��o������
	if (changed & MOTIONPLUS_DETECTED)
	{
		UE_LOG(LogTemp, Warning, TEXT("���[�V�����v���X�����o"));
		if (remote.ExtensionType == wiimote_state::NONE)
		{
			remote.EnableMotionPlus();
			UE_LOG(LogTemp, Warning, TEXT("���[�V�����v���X��L��"));
		}
	}
	// �g���R�l�N�^�Ƀ��[�V�����v���X���ڑ�����Ă���
	else if (changed & MOTIONPLUS_EXTENSION_CONNECTED)
	{
		UE_LOG(LogTemp, Warning, TEXT("�g���R�l�N�^�Ƀ��[�V�����v���X�����o"));
		if (remote.MotionPlusEnabled())
		{
			remote.EnableMotionPlus();
			UE_LOG(LogTemp, Warning, TEXT("���[�V�����v���X��L��"));
		}
	}
	// ���[�V�����v���X���g���R�l�N�^����ؒf���ꂽ��
	else if (changed & MOTIONPLUS_EXTENSION_DISCONNECTED)
	{
		// �Ăу��[�V�����v���X�̃f�[�^��L���ɂ���
		if (remote.MotionPlusConnected())
			remote.EnableMotionPlus();
	}
	// ���̑��̊g���@�킪�ڑ����ꂽ��
	else if (changed & EXTENSION_CONNECTED)
	{
		if (!remote.IsBalanceBoard())
			remote.SetReportType(wiimote::IN_BUTTONS_ACCEL_EXT);
	}
	// ���̑��̊g���@�킪�ؒf���ꂽ��
	else if (changed & EXTENSION_DISCONNECTED)
	{
		remote.SetReportType(wiimote::IN_BUTTONS_ACCEL_IR);
	}

	// ���炩�̕ω����N��������
	if (changed & CHANGED_ALL)
	{
		// ���t���b�V��
		remote.RefreshState();

		// ���[�V�����v���X�̏�ԕω����N��������
		if (changed & ACCEL_CHANGED)
		{
			//�����x
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

			UE_LOG(LogTemp, Warning, TEXT("�����x�Z���T�[  �F[X] %+2.3f [Y] %+2.3f [Z] %+2.3f\n"), remote.Acceleration.X, remote.Acceleration.Y, remote.Acceleration.Z);
			UE_LOG(LogTemp, Warning, TEXT("�����x(�l�ۂߌ�)�F[X] %+2.3f [Y] %+2.3f [Z] %+2.3f\n"), gAccel.X, gAccel.Y, gAccel.Z);

			gAccel.X -= remote.Acceleration.Orientation.X;
			gAccel.Y -= remote.Acceleration.Orientation.Y;

			gAccel.X = floor(gAccel.X * 10.0f) / 10.0f;
			gAccel.Y = floor(gAccel.Y * 10.0f) / 10.0f;
			gAccel.X += 0.1f;
			gAccel.Y += 0.1f;

			UE_LOG(LogTemp, Warning, TEXT("�����x(-�d��)   �F[X] %+2.3f [Y] %+2.3f [Z] %+2.3f\n"), gAccel.X, gAccel.Y, gAccel.Z);
			UE_LOG(LogTemp, Warning, TEXT(" "));
			UE_LOG(LogTemp, Warning, TEXT("��]�x�Z���T�[  �F[X] %+2.3f [Y] %+2.3f [Z] %+2.3f\n"), remote.Acceleration.Orientation.X, remote.Acceleration.Orientation.Y, remote.Acceleration.Orientation.Z);
			UE_LOG(LogTemp, Warning, TEXT("��]          �F[Pitch]%+2.3f [Roll]%+2.3f\n"), remote.Acceleration.Orientation.Pitch, remote.Acceleration.Orientation.Roll);
			UE_LOG(LogTemp, Warning, TEXT(" "));
			UE_LOG(LogTemp, Warning, TEXT("���x�@        �F[X] %+2.3f [Y] %+2.3f [Z] %+2.3f\n"), gVelocity.X, gVelocity.Y, gVelocity.Z);
			UE_LOG(LogTemp, Warning, TEXT("���W�@        �F[X] %+2.3f [Y] %+2.3f [Z] %+2.3f\n"), gPosition.X, gPosition.Y, gPosition.Z);
			UE_LOG(LogTemp, Warning, TEXT("UpdateAge       :%d"), remote.Acceleration.Orientation.UpdateAge);
			UE_LOG(LogTemp, Warning, TEXT(" "));

		}
	}
}