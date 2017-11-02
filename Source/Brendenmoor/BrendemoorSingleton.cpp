// Fill out your copyright notice in the Description page of Project Settings.

#include "Brendenmoor.h"
#include "BrendemoorSingleton.h"


UBrendemoorSingleton::UBrendemoorSingleton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//Events = new UGlobalEventHandler();
	//Events = ConstructObject<GlobalEventHandler>(TEXT("EventHandler"));

	
	if (Events == nullptr)
	{
		Events = NewObject<UGlobalEventHandler>();
	}

	if (BattleCommandSystem == nullptr)
	{
		BattleCommandSystem = NewObject<ABattleSystemCommandProcessor>();
		//BattleCommandSystem->BindEvents(Events);
	}
}


