// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"

UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& root, uint8* nodeMemory)
{
	Super::ExecuteTask(root, nodeMemory);
	AEnemyAI* controller = Cast<AEnemyAI>(root.GetAIOwner());
	AShooter_15404Character* myCharacter = controller-> getMyCharacter();

	if (controller->getPlayerCharacter()->isAlavie)
	{
		myCharacter->Shoot();
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
