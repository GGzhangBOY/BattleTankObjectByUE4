// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 Some component related to the game's AI behaviour
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
private:
		virtual void BeginPlay() override;
	
		ATank* GetAITank() const;
		
		void Tick(float DeltaTime)override;

		auto GetPlayerTank() const;

};
