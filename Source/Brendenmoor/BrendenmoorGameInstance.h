// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/GameInstance.h" 
#include "GlobalEventHandler.h"
#include "BattleSystemCommandProcessor.h"
#include "BrendenmoorGameInstance.generated.h"

UCLASS()
class BRENDENMOOR_API UBrendenmoorGameInstance : public UGameInstance
{
	GENERATED_BODY()

	void InitializeMembers();

	UGlobalEventHandler *mEvents = nullptr;

public:
	UBrendenmoorGameInstance(const FObjectInitializer& ObjectInitializer);
	~UBrendenmoorGameInstance();

	void Shutdown() override;

	UGlobalEventHandler* GetEventHandler();
};
