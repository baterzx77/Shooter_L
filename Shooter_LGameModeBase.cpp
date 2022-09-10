// Copyright Epic Games, Inc. All Rights Reserved.


#include "Shooter_LGameModeBase.h"
#include "ShootCharacter.h"
#include "ShooterPlayerController.h"

AShooter_LGameModeBase::AShooter_LGameModeBase()
{
	DefaultPawnClass = AShootCharacter::StaticClass();
	PlayerControllerClass = AShooterPlayerController::StaticClass();
}