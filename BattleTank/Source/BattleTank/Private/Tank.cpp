// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "../Public/Tank.h"


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
	TankAimingComponent->AimAtWorldSpace(HitLocation);
	auto ThisTankName = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("Tank: %s aim at: %s"), *ThisTankName, *HitLocation.ToString()) (Log转移到了TankAimingCompontent 中的 AimAtWorldSpace)
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATank::SetBarrelRef(UStaticMeshComponent* BarrelToSet)
{
	TankAimingComponent->SetBarrelRef(BarrelToSet);
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


