// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//#include "GameFramework/Actor.h"
//#include "BrendenmoorCharacter.h"
//#include "SelectableTarget.generated.h"

/**
 * 
 */
enum TARGET_TYPE
{
	ENEMY = 0
};

//UCLASS()
class BRENDENMOOR_API SelectableTarget //: public AActor
{
	//GENERATED_BODY()

	AActor			*pTarget;
	float			fDistanceToTarget;
	TARGET_TYPE		eTargetType;

public:
	SelectableTarget();
	~SelectableTarget();

	AActor*	GetTarget() const;
	float GetDistanceToTarget() const;
	TARGET_TYPE GetTargetType() const;

	void SetTarget(AActor* pNewTarget);
	void SetDistanceToTarget(const float fNewDistance);
	void SetTargetType(const TARGET_TYPE eNewTargetType);
};
