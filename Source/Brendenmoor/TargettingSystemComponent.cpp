// Fill out your copyright notice in the Description page of Project Settings.

#include "Brendenmoor.h"
#include "BrendenmoorCharacter.h"
#include "TargettingSystemComponent.h"


// Sets default values for this component's properties
UTargettingSystemComponent::UTargettingSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTargettingSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTargettingSystemComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...

	uiTickCounter++;

	if (uiTickCounter == UPDATE_INTERVAL)
	{
		UpdateSelectableTargetsArray();
		uiTickCounter = 0;
	}
}

AActor * UTargettingSystemComponent::GetNearestEnemy()
{
	AActor *pNearestEnemy = nullptr;
	SelectableTarget *pCurrentTarget = nullptr;

	for (INT32 arrayLocation = 0; arrayLocation < arraySelectableTargets.Num(); arrayLocation++)
	{
		if (pCurrentTarget == nullptr)
		{
			pCurrentTarget = arraySelectableTargets[arrayLocation];
		}
		else
		{
			if (pCurrentTarget->GetDistanceToTarget() > arraySelectableTargets[arrayLocation]->GetDistanceToTarget())
			{
				pCurrentTarget = arraySelectableTargets[arrayLocation];
			}
		}
	}

	if (pCurrentTarget != nullptr && pCurrentTarget->GetDistanceToTarget() < MAX_DISTANCE_FROM_TARGET_TO_BE_SELECTABLE)
	{
		pNearestEnemy = pCurrentTarget->GetTarget();
		DebugDistance = pCurrentTarget->GetDistanceToTarget();
	}

	return pNearestEnemy;
}

AActor * UTargettingSystemComponent::GetNextEnemy()
{
	return nullptr;
}

AActor * UTargettingSystemComponent::GetPreviousEnemy()
{
	return nullptr;
}

void UTargettingSystemComponent::UpdateSelectableTargetsArray()
{
	for (INT32 arrayLocation = 0; arrayLocation < arraySelectableTargets.Num(); arrayLocation++)
	{ 
		delete arraySelectableTargets[arrayLocation];
	}

	arraySelectableTargets.Empty();


	for (INT32 arrayLocation = 0; arrayLocation < arrayAllLoadedCharacters.Num(); arrayLocation++)
	{
		ABrendenmoorCharacter *pCharacter = Cast<ABrendenmoorCharacter>(arrayAllLoadedCharacters[arrayLocation]);

		if (pCharacter != nullptr && pCharacter != GetOwner())
		{
			SelectableTarget *selectableTarget = new SelectableTarget();

			FVector distanceVector = GetOwner()->GetActorLocation() - arrayAllLoadedCharacters[arrayLocation]->GetActorLocation();

			selectableTarget->SetTarget(arrayAllLoadedCharacters[arrayLocation]);
			selectableTarget->SetDistanceToTarget(distanceVector.Size());

			arraySelectableTargets.Add(selectableTarget);
		}
	}
}

