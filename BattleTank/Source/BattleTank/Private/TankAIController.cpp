// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

auto ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());//这里一定要先GetPawn()之后再进行转换，不然从PlayerController()转换到ATank类会一直失败
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AI Tank:%s"), GetPawn() ? *GetPawn()->GetName() : *FString("Owning None!!"))

		auto PlayerTank = GetPlayerTank();
}

ATank* ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		//Move towards the player
		//Aim at the player
		GetAITank()->AimAt(GetPlayerTank()->GetActorLocation());
		//Fire if ready
	}
}

