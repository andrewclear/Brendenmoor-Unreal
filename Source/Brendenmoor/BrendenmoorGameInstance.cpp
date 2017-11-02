// Fill out your copyright notice in the Description page of Project Settings.

#include "Brendenmoor.h"
#include "BrendenmoorGameInstance.h"

UBrendenmoorGameInstance::UBrendenmoorGameInstance(const FObjectInitializer& ObjectInitializer) 
			: Super(ObjectInitializer)
{
	
}

UBrendenmoorGameInstance::~UBrendenmoorGameInstance()
{

	//if (mBattleCommandSystem)
	//{
	//	mBattleCommandSystem->UnbindEvents(mEvents);
	//	mBattleCommandSystem->Destroy();
	//}

	if (mEvents)
	{
		mEvents = nullptr;
		delete mEvents;
	}

}

void UBrendenmoorGameInstance::InitializeMembers()
{
	if (mEvents == nullptr)
	{
		mEvents = NewObject<UGlobalEventHandler>();
	}

	//if (mBattleCommandSystem == nullptr)
	//{
	//	mBattleCommandSystem = NewObject<ABattleSystemCommandProcessor>();
	//	mBattleCommandSystem->BindEvents(mEvents);
	//}
}

UGlobalEventHandler* UBrendenmoorGameInstance::GetEventHandler()
{
	if (mEvents == nullptr)
	{
		InitializeMembers();
	}

	return mEvents;
}
