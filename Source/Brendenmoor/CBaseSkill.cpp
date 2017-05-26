// Fill out your copyright notice in the Description page of Project Settings.

#include "Brendenmoor.h"
#include "Engine.h"
#include "CBaseSkill.h"
#include "CStandardAttributes.h"


// Sets default values
ACBaseSkill::ACBaseSkill()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACBaseSkill::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACBaseSkill::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

//void ACBaseSkill::ExecuteSkill()
//{

//}

void ACBaseSkill::ExecuteSkill_Implementation()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Execute Skill"));
	}
}


float ACBaseSkill::CalculateBaseMeleeDamage()
{
	//D = WeaponDamage
	//aD = AmmoDamage
	//fSTR = StrengthVitalityModifier
	//BaseDamage = D + (aD)+fSTR
	
	UCStandardAttributes *attackerAttributes = Cast<UCStandardAttributes>(Attacker->GetComponentByClass(UCStandardAttributes::StaticClass()));
	UCStandardAttributes *defendersAttributes = Cast<UCStandardAttributes>(Defenders[0]->GetComponentByClass(UCStandardAttributes::StaticClass()));

	return CalculateStrengthVitalityModifier(attackerAttributes->Strength, defendersAttributes->Vitality);
}

float ACBaseSkill::CalculateStrengthVitalityModifier(float attackerStrength, float defenderVitality)
{
	float detlaStrengthVitality = attackerStrength - defenderVitality;
	float rangeModifier = 0.0f;

	if (detlaStrengthVitality <= -22.0f)
	{
		rangeModifier = 13.0f;
	}
	else if (detlaStrengthVitality > -22.0f && detlaStrengthVitality <= -16.0f)
	{
		rangeModifier = 12.0f;
	}
	else if (detlaStrengthVitality > -16.0f && detlaStrengthVitality <= -8.0f)
	{
		rangeModifier = 10.0f;
	}
	else if (detlaStrengthVitality > -8.0f && detlaStrengthVitality <= -3.0f)
	{
		rangeModifier = 9.0f;
	}
	else if (detlaStrengthVitality > -3.0f && detlaStrengthVitality <= -0.0f)
	{
		rangeModifier = 8.0f;
	}
	else if (detlaStrengthVitality > 0.0 && detlaStrengthVitality <= 5.0f)
	{
		rangeModifier = 7.0f;
	}
	else if (detlaStrengthVitality > 5.0 && detlaStrengthVitality <= 11.0f)
	{
		rangeModifier = 6.0f;
	}
	else if (detlaStrengthVitality >= 12.0f)
	{
		rangeModifier = 4.0f;
	}

	return (detlaStrengthVitality + rangeModifier) / 4;
}


