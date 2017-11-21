// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
//#include "CBaseSkill.h"
#include "GlobalEventHandler.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBattleSystemEventDelegate_OnBattleActionInitiated, AActor*, attacker, ACBaseSkill*, skillUsed);

UCLASS(meta = (BlueprintSpawnableComponent), Category = "Global Events")
class BRENDENMOOR_API UGlobalEventHandler : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Battle System Events")
	FBattleSystemEventDelegate_OnBattleActionInitiated OnBattleActionInitiated;
};
