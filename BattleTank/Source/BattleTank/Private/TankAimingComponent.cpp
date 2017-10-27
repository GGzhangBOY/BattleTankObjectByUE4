// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UTankAimingComponent::SetBarrelRef(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAtWorldSpace(FVector HitLocation,float LaunchSpeed)
{
	auto ThisTankName = GetOwner()->GetName();
	auto BarrelLocation = Barrel->GetComponentLocation();
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	FVector OutLaunchVelocity;

	bool HaveSolution = UGameplayStatics::SuggestProjectileVelocity( //获得想要击中指定的位置所需要炮管指向的角度
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if(HaveSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
		//UE_LOG(LogTemp, Warning, TEXT("Aiming at %s"), *AimDirection.ToString())
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("No solution found to hit at this location!"))
	}
	//UE_LOG(LogTemp, Warning, TEXT("Tank: %s aim at: %s from %s with the speed of %f"), *ThisTankName, *HitLocation.ToString(),*BarrelLocation.ToString(),LaunchSpeed)
}

	void UTankAimingComponent::MoveBarrel(FVector VectorToPointAt)
	{
		// Work out difference between current barrel rotationm, and Aim Direction
		auto BarrelRotator = Barrel->GetForwardVector().Rotation();
		auto AimAsRotation = VectorToPointAt.Rotation();
		auto DeltaRotation = AimAsRotation - BarrelRotator;
		//UE_LOG(LogTemp, Warning, TEXT("Aiming at %s, Left %s to rotate On brand new Visual Studio"), *AimAsRotation.ToString(), *DeltaRotation.ToString())
			Barrel->Elevate(DeltaRotation.Pitch);
	}
