// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"
//在这里可以用前置声明，但是在CPP文件中不能够用前置声明，因为CPP文件中需要用到头文件中的特定方法，必须要包含整个头文件
class UTankBarrel;
class UTankTurret;
//Give the tank ablity to aim at something through it's barrel
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelRef(UTankBarrel* BarrelToSet);

	void SetTurretRef(UTankTurret* TurretToSet);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Trigger the gun point to the player in Data
	void AimAtWorldSpace(FVector HitLocation,float LaunchSpeed);

	//Trigger the barrel to point at the location from Suggest
	void MoveBarrel(FVector VectorToPointAt);
	
private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	// TODO SetTurretReference

};
