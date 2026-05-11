// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MyBTTask_clearBB.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_15404_API UMyBTTask_clearBB : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	UMyBTTask_clearBB();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& root, uint8* nodeMemory) override;
	
};
