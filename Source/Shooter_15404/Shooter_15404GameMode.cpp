// Copyright Epic Games, Inc. All Rights Reserved.

#include "Shooter_15404GameMode.h"

AShooter_15404GameMode::AShooter_15404GameMode()
{
	// stub
}

void AShooter_15404GameMode::BeginPlay()
{
	Super::BeginPlay();
	player = Cast<AShooter_15404Character>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyAI::StaticClass(), enemyArray);

	for (AActor* temp : enemyArray)
	{
		Cast<AEnemyAI>(temp)->StartBehaviorTree(player);
	}

}
