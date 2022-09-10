// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/HealthComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AShootCharacter::AShootCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");

}

// Called when the game starts or when spawned
void AShootCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShootCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

}

// Called to bind functionality to input
void AShootCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveF", this, &AShootCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveF", this, &AShootCharacter::MoveRL);
	PlayerInputComponent->BindAxis("MoveF", this, &AShootCharacter::LookUp);
	PlayerInputComponent->BindAxis("MoveF", this, &AShootCharacter::LookRL);
}

void AShootCharacter::MoveForward(float Amount)
{
	AddMovementInput(GetActorForwardVector(), Amount);
}

void AShootCharacter::MoveRL(float Amount)
{
	AddMovementInput(GetActorRightVector(), Amount);
}

void AShootCharacter::LookUp(float Amount)
{
	AddControllerPitchInput(Amount);
}

void AShootCharacter::LookRL(float Amount)
{
	AddControllerYawInput(Amount);
}