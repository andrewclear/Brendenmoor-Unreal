// Fill out your copyright notice in the Description page of Project Settings.

#include "Brendenmoor.h"
#include "SelectableTarget.h"

SelectableTarget::SelectableTarget()
{
}

SelectableTarget::~SelectableTarget()
{
}

AActor*	SelectableTarget::GetTarget() const
{
	return pTarget;
}

float SelectableTarget::GetDistanceToTarget() const
{
	return fDistanceToTarget;
}

TARGET_TYPE SelectableTarget::GetTargetType() const
{
	return eTargetType;
}

void SelectableTarget::SetTarget(AActor *pNewTarget)
{
	pTarget = pNewTarget;
}

void SelectableTarget::SetDistanceToTarget(const float fNewDistance)
{
	fDistanceToTarget = fNewDistance;
}

void SelectableTarget::SetTargetType(const TARGET_TYPE eNewTargetType)
{
	eTargetType = eNewTargetType;
}
