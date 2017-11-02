// Fill out your copyright notice in the Description page of Project Settings.

#include "Brendenmoor.h"
#include "EngineGlobals.h"
#include "Engine/Engine.h"
#include "BrendenmoorSingletonLibrary.h"

UBrendenmoorSingletonLibrary::UBrendenmoorSingletonLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}


UBrendemoorSingleton* UBrendenmoorSingletonLibrary::GetBrendenmoorSingleton(bool& IsValid)
{
	IsValid = false;
	UBrendemoorSingleton* instance = Cast<UBrendemoorSingleton>(GEngine->GameSingleton);

	if (!instance) return NULL;
	if (!instance->IsValidLowLevel()) return NULL;

	IsValid = true;
	return instance;
}

