// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraFOVModifier.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values for this component's properties
UCameraFOVModifier::UCameraFOVModifier()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UCameraFOVModifier::BeginPlay()
{
	Super::BeginPlay();

	//Gets the player character
	PlayerCharacter = Cast<ACharacter>(GetOwner());

	//Gets the camera of the player character
	if (PlayerCharacter)
	{
		PlayerCamera = PlayerCharacter->FindComponentByClass<UCameraComponent>();
	}
}


// Called every frame
void UCameraFOVModifier::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Won't run unless there's a player and respective camera
	if (!PlayerCharacter || !PlayerCamera) return;

	//Gets current speed of player character to measure for FOV changes
	float CurrentSpeed = PlayerCharacter->GetCharacterMovement()->Velocity.Size();

	//Calculates the target FOV for the camera using the player's current speed from earlier, and the variables from the .h file
	float TargetFOV = FMath::GetMappedRangeValueClamped(FVector2D(0.f, SpeedThreshold), FVector2D(MinFOV, MaxFOV), CurrentSpeed);

	//Another calculation for interpolating the FOV changes so it's smoother
	PlayerCamera->SetFieldOfView(FMath::FInterpConstantTo(PlayerCamera->FieldOfView, TargetFOV, DeltaTime, InterpSpeed));
}

