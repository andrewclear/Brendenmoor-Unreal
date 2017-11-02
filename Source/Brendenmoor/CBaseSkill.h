// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CBaseSkill.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class ETargetType : uint8
{
	VE_Single 					UMETA(DisplayName = "Single Target Attack"),
	VE_AOEAroundTarget 			UMETA(DisplayName = "AOE Around Target"),
	VE_AOEAroundAttacker		UMETA(DisplayName = "AOE Around Attacker"),
	VE_AOEInFrontOfAttacker		UMETA(DisplayName = "AOE In Front Attacker")
};

/*
UCLASS()
class YourClass : public YourSuperClass
{
	GENERATED_UCLASS_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
		EVictoryEnum VictoryEnum;

	//Rest of Class Code
};
*/

UCLASS()
class BRENDENMOOR_API ACBaseSkill : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ACBaseSkill();

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Skills")
	AActor* Attacker;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Skills")
	TArray<AActor*> Defenders;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Skills")
	AActor* Defender;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
	ETargetType TargetTypeEnum;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Battle Skills")
	void ExecuteSkill();
	virtual void ExecuteSkill_Implementation();

	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Battle Skills")
	float CalculateBaseMeleeDamage();

protected:
	//UFUNCTION(BlueprintImplementableEvent, Category = "Battle Skills")
	//float CalculateBaseMeleeDamage();

	float CalculateStrengthVitalityModifier(float attackerStrength, float defenderVitality);
};
