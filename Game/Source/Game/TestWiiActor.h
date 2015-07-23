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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FVector)
	FVector accel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FVector)
	FVector velocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FVector)
	FVector position;
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
	UFUNCTION(BlueprintCallable, Category = "Level")
	void PushArrowButton();

private:
	wiimote remote;
	float moveSpeed;
};
