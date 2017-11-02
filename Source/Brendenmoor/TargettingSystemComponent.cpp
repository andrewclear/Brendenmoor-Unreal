// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine.h" //only for GEngine
#include "Brendenmoor.h"
#include "BrendenmoorCharacter.h"
#include "PlayableCharacter.h"
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

	CurrentTarget = nullptr;
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

void UTargettingSystemComponent::GetAllNearbyActors_Implementation()
{

}

AActor * UTargettingSystemComponent::GetNearestEnemy()
{
	AActor *pNearestEnemy = nullptr;
	SelectableTarget *pCurrentTarget = nullptr;

	for (int32 arrayLocation = 0; arrayLocation < arraySelectableTargets.Num(); arrayLocation++)
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

	if (pCurrentTarget != nullptr)// && pCurrentTarget->GetDistanceToTarget() < MAX_DISTANCE_FROM_TARGET_TO_BE_SELECTABLE)
	{
		pNearestEnemy = pCurrentTarget->GetTarget();
		DebugDistance = pCurrentTarget->GetDistanceToTarget();

		if (GEngine && (pNearestEnemy != CurrentTarget) && (Cast<APlayableCharacter>(pNearestEnemy) != nullptr))
		{
			FName name = Cast<ABrendenmoorCharacter>(pNearestEnemy)->CharacterName;

			GEngine->AddOnScreenDebugMessage(-1, 0.25f, FColor::Yellow, name.ToString());
			GEngine->AddOnScreenDebugMessage(-1, 0.25f, FColor::Yellow, FString::SanitizeFloat(DebugDistance));
		}
	}

	//CurrentTarget = pNearestEnemy;
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

bool UTargettingSystemComponent::IsCurrentTargetValid()
{
	return !(CurrentTarget == nullptr);
}

void UTargettingSystemComponent::SelectTarget(bool cycleInNextDirection)
{
	if (CurrentTarget == nullptr)
	{
		CurrentTarget = GetNearestEnemy();
	}
	else
	{
		if (cycleInNextDirection)
		{
			CurrentTarget = GetNextEnemy();
		}
		else
		{
			CurrentTarget = GetPreviousEnemy();
		}
	}
}

void UTargettingSystemComponent::UpdateSelectableTargetsArray()
{
	arrayAllLoadedCharacters.Empty();

	GetAllNearbyActors();

	for (int32 arrayLocation = 0; arrayLocation < arraySelectableTargets.Num(); arrayLocation++)
	{ 
		delete arraySelectableTargets[arrayLocation];
	}

	arraySelectableTargets.Empty();


	for (int32 arrayLocation = 0; arrayLocation < arrayAllLoadedCharacters.Num(); arrayLocation++)
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

