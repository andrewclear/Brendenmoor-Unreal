// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "SelectableTarget.h"
#include "TargettingSystemComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BRENDENMOOR_API UTargettingSystemComponent : public UActorComponent
{
	GENERATED_BODY()

	const uint16	UPDATE_INTERVAL = 10;
	const float		MAX_DISTANCE_FROM_TARGET_TO_BE_SELECTABLE = 1500.0;
	uint16			uiTickCounter = 0;

	void UpdateSelectableTargetsArray();

public:	
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Targets)
	TArray<SelectableTarget*> arraySelectableTargets;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Targets)
	TArray<AActor*> arrayAllLoadedCharacters;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Targets)
	float DebugDistance;


	// Sets default values for this component's properties
	UTargettingSystemComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UFUNCTION(BlueprintCallable, Category = "Targetting System")
	AActor*	GetNearestEnemy();

	UFUNCTION(BlueprintCallable, Category = "Targetting System")
	AActor*	GetNextEnemy();

	UFUNCTION(BlueprintCallable, Category = "Targetting System")
	AActor*	GetPreviousEnemy();

};
