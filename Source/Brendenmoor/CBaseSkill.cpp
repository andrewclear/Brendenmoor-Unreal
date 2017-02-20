// Fill out your copyright notice in the Description page of Project Settings.

#include "Brendenmoor.h"
#include "Engine.h"
#include "CBaseSkill.h"


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


