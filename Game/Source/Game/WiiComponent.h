// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AllowWindowsPlatformTypes.h"
#include "wiimote.h"
#include "HideWindowsPlatformTypes.h"

#include "Components/ActorComponent.h"
#include "WiiComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAME_API UWiiComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWiiComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = float)
		float motionPlusPitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = float)
		float motionPlusYaw;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = float)
		float motionPlusRoll;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = bool)
		bool bPushAbutton;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = bool)
		bool bPushBbutton;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = bool)
		bool bPushUpButton;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = bool)
		bool bPushDownButton;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = bool)
		bool bPushRightButton;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = bool)
		bool bPushLeftButton;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = bool)
		bool bPushHomeButton;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = bool)
		bool bPushPlusButton;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = bool)
		bool bPushMinusButton;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = bool)
		bool bPushOneButton;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = bool)
		bool bPushTwoButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = float)
		float nunchukAccelX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = float)
		float nunchukAccelY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = float)
		float nunchukAccelZ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = bool)
		bool bPushNunchukButtonZ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = bool)
		bool bPushNunchukButtonC;

private:
	wiimote remote;
	int tryCount = 0;	
};
