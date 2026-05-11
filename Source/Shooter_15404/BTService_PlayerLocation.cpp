// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocation.h"

UBTService_PlayerLocation::UBTService_PlayerLocation()
{
	NodeName = TEXT("Update Player Location");
}

void UBTService_PlayerLocation::TickNode(UBehaviorTreeComponent& ownercomp, uint8* nodeMemory, float deltaSeconds)
{
	Super::TickNode(ownercomp, nodeMemory, deltaSeconds);
	AEnemyAI* controller = Cast<AEnemyAI>(ownercomp.GetAIOwner());
	AShooter_15404Character* player = controller->getPlayerCharacter();
	UBlackboardComponent* blackboard = controller->GetBlackboardComponent();

	if (controller->LineOfSightTo(player))
	{
		controller->SetFocus(player);
		blackboard->SetValueAsVector(GetSelectedBlackboardKey(), player->GetActorLocation());
	}
	else
	{
		controller->ClearFocus(EAIFocusPriority::Gameplay);
		blackboard->ClearValue(GetSelectedBlackboardKey());
	}
}
