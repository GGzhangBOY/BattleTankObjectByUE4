// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankPlayerController.h"

ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp,Warning,TEXT("Player Tank :%s"),GetPawn()?*GetPawn()->GetName():*FString("Owning None!!"))
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) {
		//UE_LOG(LogTemp, Warning, TEXT("No controlled Tank!!"))
			return;
	}
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) 
{
	int32 ViewPortX, ViewPortY;
	GetViewportSize(ViewPortX, ViewPortY);
	auto ScreenLocation = FVector2D(ViewPortX*CrossHairX, ViewPortY*CrossHairY);
	FVector WordLocation;
	FVector WordDirection;
	if (GetLookDirection(ScreenLocation, WordLocation, WordDirection)) {
		//Get camera based start point and end point
		FVector HitStart = PlayerCameraManager->GetCameraLocation();//TODO
		FVector HitEnd = HitStart + HitRange*PlayerCameraManager->GetCameraRotation().Vector();
		if (GetLookVectorHitLocation(HitStart, HitEnd, HitLocation)) 
		{
			UE_LOG(LogTemp, Warning, TEXT("Start:%s  End:%s"), *HitStart.ToString(), *HitEnd.ToString())
		}
		
	}
	
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D &ScreenLocation, FVector &WordLocation, FVector &WordDirection)
{
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		WordLocation,
		WordDirection
	);
}


bool ATankPlayerController::GetLookVectorHitLocation(FVector& Start, FVector& End,FVector& HitLocation) const
{
	FHitResult HitInfo;
	FCollisionQueryParams TraceLine(FName(TEXT("TRACE")), true, GetPawn());
	TraceLine.bReturnPhysicalMaterial = false;
	TraceLine.bTraceComplex = true;
	TraceLine.AddIgnoredActor(GetPawn());
	if (GetWorld()->LineTraceSingleByChannel(
		OUT HitInfo,
		Start,
		End,
		ECollisionChannel::ECC_Visibility,
		TraceLine
		)) {
		HitLocation = HitInfo.Location;

		return true;
	}
	return false;

}
