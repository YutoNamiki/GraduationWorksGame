// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "TestWiiActor.h"


// Sets default values
ATestWiiActor::ATestWiiActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestWiiActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestWiiActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

