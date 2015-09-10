// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AllowWindowsPlatformTypes.h"
#include "wiimote.h"
#include "HideWindowsPlatformTypes.h"

#include "GameFramework/Actor.h"
#include "TestWiiActor.generated.h"

UCLASS()
class GAME_API ATestWiiActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATestWiiActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = float)
	float motionPlusYaw;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = float)
	float motionPlusPitch;
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

private:
	wiimote remote;
};
