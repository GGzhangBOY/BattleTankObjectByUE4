// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	ATank* GetControlledTank() const;
		
	virtual void BeginPlay() override;

	//Called Every Frame
	virtual void Tick(float DeltaTime) override;
	
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation);

	UPROPERTY(EditAnywhere)
		float CrossHairX = 0.5;
	UPROPERTY(EditAnywhere)
		float HitRange = 1000000; //The max range the tank gun can hit
	UPROPERTY(EditAnywhere)
		float CrossHairY = 0.33333;

	UFUNCTION(BlueprintCallable, Category = "TankHitInfo")
		bool GetLookVectorHitLocation(FVector& Start, FVector& End,FVector& HitLocation)const;

	bool GetLookDirection(FVector2D &ScreenLocation, FVector &WordLocation, FVector &WordDirection);
};
