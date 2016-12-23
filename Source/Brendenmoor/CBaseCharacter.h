// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "CStandardAttributes.h"
#include "CBaseCharacter.generated.h"

UCLASS()
class BRENDENMOOR_API ACBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACBaseCharacter();

	//Components
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Attributes")
	class UCStandardAttributes* standardAttributes;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
