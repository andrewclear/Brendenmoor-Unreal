// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "CBaseSkill.h"
#include "BattleSystemComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FBattleSystemEventDelegate_OnBattleActionInitiated, AActor*, attacker, ACBaseSkill*, skillUsed, TArray<AActor*>, defenders);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BRENDENMOOR_API UBattleSystemComponent : public UActorComponent
{
	GENERATED_BODY()
	ACBaseSkill *autoAttackSkill = nullptr;
	

	bool autoAttack = false;
	int32 autoAttackDelay = 2;
	int32 autoAttackDelayTimer = 0;

	FTimerHandle AutoAttackTimerHandle;
	void UpdateAutoAttackTimer();

	void ResetAutoAttackDelayTimer();

public:	
	// Sets default values for this component's properties
	UBattleSystemComponent();

	//UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Battle Events")
	FBattleSystemEventDelegate_OnBattleActionInitiated onBattleActionInitiated;

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UFUNCTION(BlueprintCallable, Category = "Skills")
	bool IsAttacking();

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void StartAutoAttack(ACBaseSkill *newAutoAttackSkill);

	UFUNCTION(BlueprintCallable, Category = "Skills")
	void StopAutoAttack();
};
