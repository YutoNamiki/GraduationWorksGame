// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "PathFinderInterface.h"
#include "GettingStartNode.generated.h"

UCLASS()
class GAME_API UGettingStartNode : public UObject, public IPathFinderInterface
{
	GENERATED_BODY()

public:
	virtual EPathFindingState FindPath(UWorld* world, FPathFindingInformation& pathFindInfo, TArray<FVector>& resultRoute) override;

private:
	float minDistance;
	int32 index = 0;
};
