// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "TankPlayerController.h"

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (!PlayerTank || !ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("PlayerTank or ControlledTank not found "));
		return;
	}

	//move towards the player 
	MoveToActor(PlayerTank, AcceptanceRadius);

	//Aim towards the player 
	ControlledTank->AimAt(PlayerTank->GetActorLocation());
	ControlledTank->Fire(); //TODO limit firing rate  

}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

