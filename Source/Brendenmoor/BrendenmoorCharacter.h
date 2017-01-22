// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "CStandardAttributes.h"
#include "TargettingSystemComponent.h"
#include "BrendenmoorCharacter.generated.h"

//DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FBattleSystemEventDelegate_OnBattleActionInitiated, ACBaseCharacter*, attacker, ACBaseSkill*, skillUsed, TArray<ACBaseCharacter*>, defenders);


UCLASS(config=Game)
class ABrendenmoorCharacter : public ACharacter
{
	GENERATED_BODY()

	
public:
	ABrendenmoorCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	//Components
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Attributes")
	class UCStandardAttributes* standardAttributes;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Battle System")
	class UTargettingSystemComponent* targettingSystem;

	/** Character Name. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
	FName CharacterName;

	//UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Battle Events")
	//FBattleSystemEventDelegate_OnBattleActionInitiated onBattleActionInitiated;

	UFUNCTION(BlueprintCallable, Category = "Targetting System")
	void UpdateCharacterArray(TArray<AActor*> pCharacterArray);

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

};

