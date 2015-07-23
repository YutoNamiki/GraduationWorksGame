// Fill out your copyright notice in the Description page of Project Settings.

#include "Game.h"
#include "TestMyoPawn.h"


// Sets default values
ATestMyoPawn::ATestMyoPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ATestMyoPawn::BeginPlay()
{
	Super::BeginPlay();
	
	myoAccelerarion = FVector(myoAccelerarion.ZeroVector);
	myoOrientationPitch = 0.0f;
	myoOrientationYaw = 0.0f;
	myoOrientationRoll = 0.0f;

	bMyoPoseRest = false;
	bMyoPoseFist = false;
	bMyoPoseFingersSpread = false;
	bMyoPoseDoubleTap = false;

	accelXatFist = 0.0f;
	bCanPullString = false;
	bCanShootArrow = false;
}

// Called every frame
void ATestMyoPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (bMyoPoseFist)
	{
		if (accelXatFist == 0.0f)
		{
			accelXatFist = myoAccelerarion.X;
			bCanPullString = true;
		}
	}

	if (bCanPullString)
	{
		if (abs(myoAccelerarion.X - accelXatFist) > 0.5f)
		{
			bCanShootArrow = true;
		}
	}

	if (bMyoPoseFingersSpread && bCanShootArrow)
	{
		accelXatFist = 0.0f;
		bCanShootArrow = false;
		UE_LOG(LogTemp, Warning, TEXT("shoot arrow!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"));
	}

	/*UE_LOG(LogTemp, Warning, TEXT("Acceleration [X]    :%f [Y]  :%f [Z]   :%f"), myoAccelerarion.X, myoAccelerarion.Y, myoAccelerarion.Z);
	UE_LOG(LogTemp, Warning, TEXT("Orientation  [Pitch]:%f [Yaw]:%f [Roll]:%f"), myoOrientationPitch, myoOrientationYaw, myoOrientationRoll);
	UE_LOG(LogTemp, Warning, TEXT("accelXatFist:%f bCanShoot:%d"), accelXatFist, bCanShootArrow);
	UE_LOG(LogTemp, Warning, TEXT("Pose [Rest]:%d [Fist]:%d [Spred]:%d [Tap]:%d"), bMyoPoseRest, bMyoPoseFist, bMyoPoseFingersSpread, bMyoPoseDoubleTap);*/
	
}

// Called to bind functionality to input
void ATestMyoPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAction("MyoPoseRest", IE_Pressed, this, &ATestMyoPawn::MyoPoseRestOn);
	InputComponent->BindAction("MyoPoseFist", IE_Pressed, this, &ATestMyoPawn::MyoPoseFistOn);
	InputComponent->BindAction("MyoPoseFingersSpread", IE_Pressed, this, &ATestMyoPawn::MyoPoseFingersSpreadOn);
	InputComponent->BindAction("MyoPoseDoubleTap", IE_Pressed, this, &ATestMyoPawn::MyoPoseDoubleTapOn);

	InputComponent->BindAction("MyoPoseRest", IE_Released, this, &ATestMyoPawn::MyoPoseRestOff);
	InputComponent->BindAction("MyoPoseFist", IE_Released, this, &ATestMyoPawn::MyoPoseFistOff);
	InputComponent->BindAction("MyoPoseFingersSpread", IE_Released, this, &ATestMyoPawn::MyoPoseFingersSpreadOff);
	InputComponent->BindAction("MyoPoseDoubleTap", IE_Released, this, &ATestMyoPawn::MyoPoseDoubleTapOff);

	InputComponent->BindAxis("MyoAccelerationX", this, &ATestMyoPawn::MyoAccelerationX);
	InputComponent->BindAxis("MyoAccelerationY", this, &ATestMyoPawn::MyoAccelerationY);
	InputComponent->BindAxis("MyoAccelerationZ", this, &ATestMyoPawn::MyoAccelerationZ);

	InputComponent->BindAxis("MyoOrientationPitch", this, &ATestMyoPawn::MyoOrientationPitch);
	InputComponent->BindAxis("MyoOrientationYaw", this, &ATestMyoPawn::MyoOrientationYaw);
	InputComponent->BindAxis("MyoOrientationRoll", this, &ATestMyoPawn::MyoOrientationRoll);
}

void ATestMyoPawn::MyoPoseRestOn()
{
	bMyoPoseRest = true;
}

void ATestMyoPawn::MyoPoseFistOn()
{
	bMyoPoseFist = true;
}

void ATestMyoPawn::MyoPoseFingersSpreadOn()
{
	bMyoPoseFingersSpread = true;
}

void ATestMyoPawn::MyoPoseDoubleTapOn()
{
	bMyoPoseDoubleTap = true;
}

void ATestMyoPawn::MyoPoseRestOff()
{
	bMyoPoseRest = false;
}

void ATestMyoPawn::MyoPoseFistOff()
{
	bMyoPoseFist = false;
}

void ATestMyoPawn::MyoPoseFingersSpreadOff()
{
	bMyoPoseFingersSpread = false;
}

void ATestMyoPawn::MyoPoseDoubleTapOff()
{
	bMyoPoseDoubleTap = false;
}

void ATestMyoPawn::MyoAccelerationX(float Value)
{
	myoAccelerarion.X = Value;
}

void ATestMyoPawn::MyoAccelerationY(float Value)
{
	myoAccelerarion.Y = Value;
}

void ATestMyoPawn::MyoAccelerationZ(float Value)
{
	myoAccelerarion.Z = Value;
}

void ATestMyoPawn::MyoOrientationPitch(float Value)
{
	myoOrientationPitch = Value;
}

void ATestMyoPawn::MyoOrientationYaw(float Value)
{
	myoOrientationYaw = Value;
}

void ATestMyoPawn::MyoOrientationRoll(float Value)
{
	myoOrientationRoll = Value;
}

void ATestMyoPawn::MyoVibrate()
{
	IMyoPlugin::Get().VibrateDevice(1, MYO_VIBRATION_SHORT);
}