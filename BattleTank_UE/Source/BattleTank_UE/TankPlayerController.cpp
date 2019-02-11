// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::AimTowardCrosshair() {
	if (!GetControlledTank()) {
		return;
	}
	FVector HitLocation; //out parameter
	if (GetSightRayHitLocation(HitLocation)) {
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	}
}
void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
}
ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}
void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	ATank* tank = nullptr;
	tank = GetControlledTank();
	if (!tank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not posessing a tank..."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController posessing: %s"), *(tank->GetName()));
	}
}
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const {
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairX, ViewportSizeY * CrossHairY);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		//
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const {
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, OutLookDirection);
}
