// Fill out your copyright notice in the Description page of Project Settings.

#include "Brendenmoor.h"
#include "Engine.h"
#include "BattleSystemCommandProcessor.h"
#include "BrendenmoorGameInstance.h"
#include "BrendenmoorSingletonLibrary.h"


// Sets default values
ABattleSystemCommandProcessor::ABattleSystemCommandProcessor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABattleSystemCommandProcessor::BindEvents(UGlobalEventHandler *Events)
{
	if (Events)
	{
		if (Events->OnBattleActionInitiated.IsBound())
		{
			Events->OnBattleActionInitiated.RemoveDynamic(this, &ABattleSystemCommandProcessor::OnBattleActionInitiated);
		}

		Events->OnBattleActionInitiated.AddDynamic(this, &ABattleSystemCommandProcessor::OnBattleActionInitiated);

		if (GEngine)
		{
			test = Events->GetName();
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, Events->GetName());
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Binding OnBindBattleActionInitiated"));
		}
	}
}

void ABattleSystemCommandProcessor::UnbindEvents(UGlobalEventHandler *Events)
{
	if (Events)
	{
		if (GEngine)
		{
			test = Events->GetName();
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, Events->GetName());
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Unbinding OnBindBattleActionInitiated"));
		}
	}

	if (Events->OnBattleActionInitiated.IsBound())
	{
		Events->OnBattleActionInitiated.RemoveDynamic(this, &ABattleSystemCommandProcessor::OnBattleActionInitiated);
	}
}


// Called when the game starts or when spawned
void ABattleSystemCommandProcessor::BeginPlay()
{
	Super::BeginPlay();

	UBrendenmoorGameInstance *gameInstance = Cast<UBrendenmoorGameInstance>(GetGameInstance());

	if (gameInstance)
	{
		gameInstance->GetEventHandler()->OnBattleActionInitiated.AddDynamic(this, &ABattleSystemCommandProcessor::OnBattleActionInitiated);
	}
	
}

void ABattleSystemCommandProcessor::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	UBrendenmoorGameInstance *gameInstance = Cast<UBrendenmoorGameInstance>(GetGameInstance());

	//if (isValid)
	if (gameInstance)
	{
		gameInstance->GetEventHandler()->OnBattleActionInitiated.RemoveDynamic(this, &ABattleSystemCommandProcessor::OnBattleActionInitiated);
	}
}

void ABattleSystemCommandProcessor::OnBattleActionInitiated(AActor *attacker, ACBaseSkill *skillUsed)
{
	//for (int i = 0; i < defenders.Num(); i++)
	//{
	//	skillUsed->Defender = defenders[i];
	skillUsed->Attacker = attacker;
	skillUsed->ExecuteSkill();
	//}
}

// Called every frame
void ABattleSystemCommandProcessor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

