// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "../Public/Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//There is no need to protect the point as adding to the constructor
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAtWorldSpace(HitLocation, LaunchSpeed);
	auto ThisTankName = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("Tank: %s aim at: %s"), *ThisTankName, *HitLocation.ToString()) (Log转移到了TankAimingCompontent 中的 AimAtWorldSpace)
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATank::SetBarrelRef(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelRef(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretRef(UTankTurret * TurretToSet)
{
	TankAimingComponent->SetTurretRef(TurretToSet);
}

void ATank::Firing()
{
	UE_LOG(LogTemp, Warning, TEXT("Firing"));
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;//Ginving a reload time to control the tank's firing rate;
	if (Barrel && isReloaded)
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
	else
	{
		return;
	}
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


