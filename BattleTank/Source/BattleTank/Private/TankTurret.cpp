// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp(RelativeSpeed, (float)-2, (float)2);//Limit the max speed of the turret to rotate
	auto Time = GetWorld()->GetTimeSeconds();

	//UE_LOG(LogTemp, Warning, TEXT("%f : Moving Turret at the degree of %f"), Time, RelativeSpeed)
		auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->GetDeltaSeconds();
	auto OriginNewRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, OriginNewRotation, 0));
}
