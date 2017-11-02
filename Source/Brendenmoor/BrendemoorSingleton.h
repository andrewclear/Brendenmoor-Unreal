// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "Brendenmoor.h"
#include "GlobalEventHandler.h"
#include "BattleSystemCommandProcessor.h"
#include "BrendemoorSingleton.generated.h"

UCLASS(Blueprintable, BlueprintType)
class BRENDENMOOR_API  UBrendemoorSingleton : public UObject
{
	GENERATED_BODY()

public:
	UBrendemoorSingleton(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Brendenmoor Data Singleton")
	UGlobalEventHandler *Events = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Brendenmoor Data Singleton")
	ABattleSystemCommandProcessor *BattleCommandSystem = nullptr;
};
