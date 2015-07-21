// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "TestMyoPawn.generated.h"

UCLASS()
class GAME_API ATestMyoPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATestMyoPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	FVector myoAccelerarion;
	float myoOrientationPitch;
	float myoOrientationYaw;
	float myoOrientationRoll;

	bool bMyoPoseRest;
	bool bMyoPoseFist;
	bool bMyoPoseFingersSpread;
	bool bMyoPoseDoubleTap;

	void MyoAccelerationX(float Value);
	void MyoAccelerationY(float Value);
	void MyoAccelerationZ(float Value);

	void MyoOrientationPitch(float Value);
	void MyoOrientationYaw(float Value);
	void MyoOrientationRoll(float Value);

	void MyoPoseRestOn();
	void MyoPoseFistOn();
	void MyoPoseFingersSpreadOn();
	void MyoPoseDoubleTapOn();

	void MyoPoseRestOff();
	void MyoPoseFistOff();
	void MyoPoseFingersSpreadOff();
	void MyoPoseDoubleTapOff();

	float accelXatFist;

	bool bCanPullString;
	bool bCanShootArrow;
	
};
