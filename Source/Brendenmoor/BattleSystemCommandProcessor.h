// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CBaseSkill.h"
#include "BattleSystemComponent.h"
#include "BattleSystemCommandProcessor.generated.h"

//DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FBattleSystemEventDelegate_OnBattleActionInitiated, AActor*, attacker, ACBaseSkill*, skillUsed, TArray<AActor*>, defenders);

UCLASS()
class BRENDENMOOR_API ABattleSystemCommandProcessor : public AActor
{
	GENERATED_BODY()

	FBattleSystemEventDelegate_OnBattleActionInitiated onBattleActionInitiated;
	
	UFUNCTION()
	void BindOnBattleActionInitiated(AActor *attacker, ACBaseSkill *skillUsed, TArray<AActor*> defenders);

public:	
	// Sets default values for this actor's properties
	ABattleSystemCommandProcessor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
