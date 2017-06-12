// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CBaseAttributes.h"
#include "CStandardAttributes.generated.h"

/**
 * 
 */
UCLASS()
class BRENDENMOOR_API UCStandardAttributes : public UCBaseAttributes
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32			Strength;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32			Vitality;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32			Dexterity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32			Agility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32			Mind;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32			Intelligence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32			CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32			MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32			Mana;
	
	UFUNCTION(BlueprintCallable, Category = "Battle System")
	void			TakeDamage(int32 amountOfDamage);
};
