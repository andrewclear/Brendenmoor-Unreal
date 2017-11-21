// Fill out your copyright notice in the Description page of Project Settings.

#include "Brendenmoor.h"
#include "BrendenmoorGameInstance.h"

UBrendenmoorGameInstance::UBrendenmoorGameInstance(const FObjectInitializer& ObjectInitializer) 
			: Super(ObjectInitializer)
{
	
}

UBrendenmoorGameInstance::~UBrendenmoorGameInstance()
{
	/*
	if (!mEvents) return;
	if (!mEvents->IsValidLowLevel()) return;

	mEvents->ConditionalBeginDestroy(); //instantly clears UObject out of memory
	mEvents = nullptr;
	*/

	if (mEvents)
	{
		mEvents->RemoveFromRoot();
		delete mEvents;
		mEvents = nullptr;
	}
}

void UBrendenmoorGameInstance::Shutdown()
{
	Super::Shutdown();

	if (!mEvents) return;
	if (!mEvents->IsValidLowLevel()) return;

	mEvents->RemoveFromRoot();
	mEvents->ConditionalBeginDestroy(); //instantly clears UObject out of memory
	mEvents = nullptr;
}

void UBrendenmoorGameInstance::InitializeMembers()
{
	if (mEvents == nullptr)
	{
		mEvents = NewObject<UGlobalEventHandler>(this);
		mEvents->AddToRoot();
	}
}

UGlobalEventHandler* UBrendenmoorGameInstance::GetEventHandler()
{
	if (mEvents == nullptr)
	{
		InitializeMembers();
	}

	return mEvents;
}
