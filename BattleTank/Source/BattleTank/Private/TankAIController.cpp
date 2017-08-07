// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("%s"), GetPawn() ? *GetPawn()->GetName() : *FString("Owning None!!"))
}

ATank* ATankAIController::GetThePlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController());
}
