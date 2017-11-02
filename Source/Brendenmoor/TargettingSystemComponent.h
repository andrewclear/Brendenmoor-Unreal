// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "SelectableTarget.h"
#include "TargettingSystemComponent.generated.h"


//UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
UCLASS(Blueprintable, BlueprintType)
class BRENDENMOOR_API UTargettingSystemComponent : public UActorComponent
{
	GENERATED_BODY()

	const uint16	UPDATE_INTERVAL = 10;
	uint16			uiTickCounter = 0;

	void UpdateSelectableTargetsArray();

public:	
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Targets)
	TArray<SelectableTarget*> arraySelectableTargets;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Targets)
	TArray<AActor*> arrayAllLoadedCharacters;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Targets)
	float DebugDistance;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Targets)
	AActor* CurrentTarget;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Targets)
	float RadiusForSphereTrace = 2000.0;

	// Sets default values for this component's properties
	UTargettingSystemComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Battle Skills")
	void GetAllNearbyActors();
	void GetAllNearbyActors_Implementation();

	UFUNCTION(BlueprintCallable, Category = "Targetting System")
	AActor*	GetNearestEnemy();

	UFUNCTION(BlueprintCallable, Category = "Targetting System")
	AActor*	GetNextEnemy();

	UFUNCTION(BlueprintCallable, Category = "Targetting System")
	AActor*	GetPreviousEnemy();

	UFUNCTION(BlueprintCallable, Category = "Targetting System")
	bool IsCurrentTargetValid();

	UFUNCTION(BlueprintCallable, Category = "Targetting System")
	void SelectTarget(bool cycleInNextDirection);

};
