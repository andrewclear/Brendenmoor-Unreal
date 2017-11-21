// Fill out your copyright notice in the Description page of Project Settings.

#include "Brendenmoor.h"
#include "TimerManager.h"
#include "Engine.h"
#include "BrendenmoorCharacter.h"
#include "BrendenmoorGameInstance.h"
#include "GlobalEventHandler.h"
#include "BattleSystemComponent.h"
#include "BrendenmoorSingletonLibrary.h"


// Sets default values for this component's properties
UBattleSystemComponent::UBattleSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBattleSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(AutoAttackTimerHandle, this, &UBattleSystemComponent::UpdateAutoAttackTimer, 1.0f, true);
	GetWorld()->GetTimerManager().PauseTimer(AutoAttackTimerHandle);
	// ...
	
}


// Called every frame
void UBattleSystemComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (autoAttack == true)
	{
		if (autoAttackDelayTimer >= autoAttackDelay)
		{
			if (Cast<ABrendenmoorCharacter>(GetOwner())->targettingSystem->CurrentTarget == nullptr)
			{
				StopAutoAttack();
				return;
			}

			UBrendenmoorGameInstance *gameInstance = nullptr;
			UGameInstance *uncastedInstance;

			if (GetWorld() && GetWorld()->GetGameInstance())
			{
				uncastedInstance = GetWorld()->GetGameInstance();
				gameInstance = Cast<UBrendenmoorGameInstance>(uncastedInstance);
			}

			if (gameInstance)
			{
				gameInstance->GetEventHandler()->OnBattleActionInitiated.Broadcast(GetOwner(), autoAttackSkill);
			}

			ResetAutoAttackDelayTimer();
		}
	}
}

bool UBattleSystemComponent::IsAttacking()
{
	return autoAttack;
}

void UBattleSystemComponent::ResetAutoAttackDelayTimer()
{
	autoAttackDelayTimer = 0;
}

void UBattleSystemComponent::StartAutoAttack(ACBaseSkill *newAutoAttackSkill)
{
	if (autoAttack == false)
	{
		autoAttack = true;
		autoAttackSkill = newAutoAttackSkill;

		ResetAutoAttackDelayTimer();
		GetWorld()->GetTimerManager().UnPauseTimer(AutoAttackTimerHandle);
	}
}

void UBattleSystemComponent::StopAutoAttack()
{
	if (autoAttack == true)
	{
		autoAttack = false;
		autoAttackSkill = nullptr;

		GetWorld()->GetTimerManager().PauseTimer(AutoAttackTimerHandle);
	}
}

void UBattleSystemComponent::UpdateAutoAttackTimer()
{
	autoAttackDelayTimer++;
}

