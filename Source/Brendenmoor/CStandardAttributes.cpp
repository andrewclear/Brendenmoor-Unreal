// Fill out your copyright notice in the Description page of Project Settings.

#include "Brendenmoor.h"
#include "CStandardAttributes.h"

UFUNCTION(BlueprintCallable, Category = "Battle System")
void	UCStandardAttributes::TakeDamage(int32 amountOfDamage)
{
	Health -= amountOfDamage;
}


