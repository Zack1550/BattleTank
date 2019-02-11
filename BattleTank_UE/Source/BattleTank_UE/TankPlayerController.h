// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //must be last include

/**
 * 
 */
UCLASS()
class BATTLETANK_UE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void AimTowardCrosshair();
	void Tick(float DeltaTime) override;
	ATank* GetControlledTank() const;
	void BeginPlay() override;
private:
	bool GetSightRayHitLocation(FVector & HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector & OutLookDirection) const;
	UPROPERTY(EditAnywhere)
	float CrossHairX = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairY = 0.3333;
};
