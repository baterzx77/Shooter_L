// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealthComponent.h"
#include "GameFramework/Actor.h"
#include "Dev/FireDamageType.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	Health = MaxHealth;
	// ...
	AActor* ComponentOwner = GetOwner();
	if (ComponentOwner)
	{
		ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::OnTakeAnyDamageHandle);
	}
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	SetHealth(MaxHealth);
	// ...
	
}

void UHealthComponent::OnTakeAnyDamageHandle(
	AActor* DamageActor, float Damage, const class UDamageType* DamageType,
	class AController* InstigatedBy, AActor* DanageCauser)
{
	SetHealth(Health -= Damage);
	//if (Damage <= 0.0f || IsDead() || !GetWorld())return;
	if (DamageType)
	{
		if (DamageType->IsA<UFireDamageType>())
		{
			UE_LOG(LogTemp, Warning, TEXT("FireDamage"));
		}
	}

	/*if (IsDead())
	{
		OnDeath.Broadcast();
	}*/
	//else if (AutoHeal )
	//{
		GetWorld()->GetTimerManager().SetTimer(HealTimeHandle, this, &UHealthComponent::HealUpdate
			, HealUpdaeTime, true, HealDelay);
	//}
}

void UHealthComponent::HealUpdate()
{
	SetHealth(Health + HealModifier);
	//Health += FMath::Min(Health+HealModifier,MaxHealth);
	//OnHealChanged.Broadcast(Health);
	if (FMath::IsNearlyEqual(Health, MaxHealth) && GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(HealTimeHandle);
	}
}

void UHealthComponent::SetHealth(float NewHealth)
{
	Health = FMath::Clamp(NewHealth, 0.0f, MaxHealth);
	//OnHealthChanged.Broadcast(Health);
}