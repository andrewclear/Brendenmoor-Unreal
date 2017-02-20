// Fill out your copyright notice in the Description page of Project Settings.

#include "Brendenmoor.h"
#include "Engine.h"
#include "BattleSystemCommandProcessor.h"


// Sets default values
ABattleSystemCommandProcessor::ABattleSystemCommandProcessor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABattleSystemCommandProcessor::BeginPlay()
{
	Super::BeginPlay();

	//GetWorld()->GetGameState()->onBattleActionInitiated.AddDynamic(this, &ABattleSystemCommandProcessor::BindOnBattleActionInitiated);
	//FSharedRef< UBattleSystemComponent > BattleSystemComponent(new UBattleSystemComponent());
	
	//WriteToLogDelegate.BindSP(BattleSystemComponent, &UBattleSystemComponent::onBattleActionInitiated);

	onBattleActionInitiated.AddDynamic(this, &ABattleSystemCommandProcessor::BindOnBattleActionInitiated);
	
}

void ABattleSystemCommandProcessor::BindOnBattleActionInitiated(AActor *attacker, ACBaseSkill *skillUsed, TArray<AActor*> defenders)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("OnBindBattleActionInitiated"));
	}
}

// Called every frame
void ABattleSystemCommandProcessor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

