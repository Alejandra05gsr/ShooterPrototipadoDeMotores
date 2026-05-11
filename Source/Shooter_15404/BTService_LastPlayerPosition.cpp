// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_LastPlayerPosition.h"

UBTService_LastPlayerPosition::UBTService_LastPlayerPosition()
{
	NodeName = TEXT("Update Last Known Player Location");
}

void UBTService_LastPlayerPosition::TickNode(UBehaviorTreeComponent& ownercomp, uint8* nodeMemory, float deltaSeconds)
{
	Super::TickNode(ownercomp, nodeMemory, deltaSeconds);
	AEnemyAI* controller = Cast<AEnemyAI>(ownercomp.GetAIOwner());
	AShooter_15404Character* player = controller->getPlayerCharacter();
	UBlackboardComponent* blackboard = controller->GetBlackboardComponent();

	if (player)
	{
		blackboard->SetValueAsVector("LastKnownLocation", player->GetActorLocation());
	}

}
