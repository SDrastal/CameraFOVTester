// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CameraFOVModifier.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CAMERAFOVTESTER_API UCameraFOVModifier : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UCameraFOVModifier();

	//The minimum FOV that the camera can be
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera FOV")
	float MinFOV = 90.f;

	//The maximum FOV that the camera can be
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera FOV")
	float MaxFOV = 125.f;

	//How fast the FOV interpolates to the target FOV depending on the player's speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera FOV")
	float InterpSpeed = 9.f;

	//Speed that the player needs to be moving to reach the Maximum FOV (this was set to the max speed of the character when using a dash)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera FOV")
	float SpeedThreshold = 1800.f;

private:
	//Gets address of the player to use later
	class ACharacter* PlayerCharacter;
	
	//Gets the address of the player's camera to use later
	class UCameraComponent* PlayerCamera;
};
