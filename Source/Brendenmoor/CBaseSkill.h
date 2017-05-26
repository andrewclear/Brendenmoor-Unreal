// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CBaseSkill.generated.h"

UCLASS()
class BRENDENMOOR_API ACBaseSkill : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ACBaseSkill();

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Skills")
	AActor* Attacker;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Skills")
	TArray<AActor*> Defenders;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Battle Skills")
	void ExecuteSkill();
	virtual void ExecuteSkill_Implementation();

	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Battle Skills")
	float CalculateBaseMeleeDamage();

protected:
	//UFUNCTION(BlueprintImplementableEvent, Category = "Battle Skills")
	//float CalculateBaseMeleeDamage();

	float CalculateStrengthVitalityModifier(float attackerStrength, float defenderVitality);
};
