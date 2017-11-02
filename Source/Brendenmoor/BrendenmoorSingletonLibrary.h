// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BrendemoorSingleton.h"
#include "BrendenmoorSingletonLibrary.generated.h"

UCLASS()
class BRENDENMOOR_API UBrendenmoorSingletonLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UBrendenmoorSingletonLibrary(const FObjectInitializer& ObjectInitializer);
	
	UFUNCTION(BlueprintPure, Category = "Brendenmoor Singleton")
	static UBrendemoorSingleton* GetBrendenmoorSingleton(bool& IsValid);
};
