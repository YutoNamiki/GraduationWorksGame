// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MyoDelegate.h"
#include "IMyoPlugin.h"

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

	UFUNCTION(BlueprintCallable, Category = "Level")
	void MyoShortVibrate();
	UFUNCTION(BlueprintCallable, Category = "Level")
	void MyoMediumVibrate();
	UFUNCTION(BlueprintCallable, Category = "Level")
	void MyoLongVibrate();

	
private:
	const int VIBRATE_SHORT_TIME = 80;
	const int VIBRATE_MEDIUM_TIME = 40;
	const int VIBRATE_LONG_TIME = 60;

	int vibrateShortTime;
	int vibrateMediumTime;
	int vibrateLongTime;

	bool bDoVibrateShort;
	bool bDoVibrateMedium;
	bool bDoVibrateLong;
};
