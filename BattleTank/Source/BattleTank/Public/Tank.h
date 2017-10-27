// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable,Category = SetUp)
	void SetBarrelRef(UTankBarrel* BarrelToSet);//因为Tank是Pawn类，所以主炮引用只能由这里向蓝图中进行暴露

protected:
	UTankAimingComponent* TankAimingComponent = NULL;
private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
 
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 100000;		//Get the launch speed of 1000m/s
};
