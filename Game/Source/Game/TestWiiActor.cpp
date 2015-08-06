// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "TestWiiActor.h"

void on_state_change(wiimote& remote, state_change_flags changed, const wiimote_state& new_state);

bool bConnected;
float gSpeedYaw = 0.0f;
float gSpeedPitch = 0.0f;
float gSpeedRoll = 0.0f;

// Sets default values
ATestWiiActor::ATestWiiActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bConnected = false;

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
		remote.EnableMotionPlus();
	}
	// �g���R�l�N�^�Ƀ��[�V�����v���X���ڑ�����Ă���
	else if (changed & MOTIONPLUS_EXTENSION_CONNECTED) 
	{
		if (remote.MotionPlusEnabled())
			remote.EnableMotionPlus();
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
		if (changed & MOTIONPLUS_SPEED_CHANGED) {
			gSpeedYaw = remote.MotionPlus.Speed.Yaw;
			gSpeedPitch = remote.MotionPlus.Speed.Pitch;
			gSpeedRoll = remote.MotionPlus.Speed.Roll;
		}
	}
}