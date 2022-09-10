// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTER_L_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();
	float GetHealth() { return Health; }

	UFUNCTION(BlueprintCallable)
		bool IsDead() const { return FMath::IsNearlyZero(Health); }

	void OnTakeAnyDamageHandle(AActor* DamageActor, float Damage, const class UDamageType* DamageType,
		class AController* InstigatedBy, AActor* DanageCauser);
protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	float MaxHealth = 100;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal")
		bool AutoHeal = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal", meta = (EditCondition = "Autoheal"))
		float HealUpdaeTime = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal", meta = (EditCondition = "Autoheal"))
		float HealDelay = 3.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal", meta = (EditCondition = "Autoheal"))
		float HealModifier = 5.0f;

	// Called when the game starts
	virtual void BeginPlay() override;
private:

	FTimerHandle HealTimeHandle;
	float Health = 0.0f;

	void HealUpdate();

	void SetHealth(float NewHealth);

};
