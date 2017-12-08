// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))//必须要加上BlueprintSpawnableComponent 
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//
	void Elevate(float  RelativeSpeed);
private:
	UPROPERTY(EditAnywhere)
		float MaxDegreesPerSecond = 8;
	UPROPERTY(EditAnywhere)
		float MinElevationDegree = -6;
	UPROPERTY(EditAnywhere)
		float MaxElevationDegree = 40;
};
