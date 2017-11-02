// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CBaseSkill.h"
#include "BattleSystemComponent.h"
#include "GlobalEventHandler.h"
#include "BattleSystemCommandProcessor.generated.h"

UCLASS(Blueprintable, BlueprintType)
class BRENDENMOOR_API ABattleSystemCommandProcessor : public AActor
{
	GENERATED_BODY()

	UFUNCTION()
	void OnBattleActionInitiated(AActor *attacker, ACBaseSkill *skillUsed);

	FString test;

public:	
	// Sets default values for this actor's properties
	ABattleSystemCommandProcessor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void BindEvents(UGlobalEventHandler *Events);
	void UnbindEvents(UGlobalEventHandler *Events);

	
	
};
