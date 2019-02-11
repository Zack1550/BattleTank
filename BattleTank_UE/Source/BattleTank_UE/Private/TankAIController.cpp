// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankAIController.h"

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	ATank* tank = nullptr;
	tank = GetControlledTank();
	if (!tank) {
		UE_LOG(LogTemp, Warning, TEXT("TankAI not posessing a tank..."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankAI posessing: %s"), *(tank->GetName()));
	}
}

ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerTank);
}