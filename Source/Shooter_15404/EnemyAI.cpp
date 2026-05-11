// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAI.h"

void AEnemyAI::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemyAI::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	//MoveToActor(playerPawn);
}

void AEnemyAI::StartBehaviorTree(AShooter_15404Character* character)
{
	if (enemyTree)
	{
		myCharacter = Cast<AShooter_15404Character>(GetPawn()); //Enemigo
		playerPawn = character;

		RunBehaviorTree(enemyTree);
		if (myCharacter || playerPawn)
		{
			UBlackboardComponent* blackboard = GetBlackboardComponent();
			if (blackboard)
			{
				GetBlackboardComponent()->SetValueAsVector("StartLocation", myCharacter->GetActorLocation());
				GetBlackboardComponent()->SetValueAsVector("PlayerLocation", playerPawn->GetActorLocation());
			}
		}
	}
}
