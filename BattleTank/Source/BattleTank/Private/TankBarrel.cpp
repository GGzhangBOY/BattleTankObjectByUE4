// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp(RelativeSpeed, (float)-1, (float)1);//Limit the max speed of the barrel to rotate
		auto Time = GetWorld()->GetTimeSeconds();

	//UE_LOG(LogTemp, Warning, TEXT("%f : Moving Barrel at the degree of %f"), Time, RelativeSpeed)
		auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->GetDeltaSeconds();
		auto OriginNewElevation = RelativeRotation.Pitch + ElevationChange;

		auto NewElevation = FMath::Clamp(OriginNewElevation, MinElevationDegree, MaxElevationDegree);
		SetRelativeRotation(FRotator(NewElevation, 0, 0));
}
