// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Shooter_15404Character.h"
#include "EnemyAI.h"
#include "Shooter_15404GameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class AShooter_15404GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	/** Constructor */
	AShooter_15404GameMode();

protected:
	virtual void BeginPlay() override;

	AShooter_15404Character* player;

	UPROPERTY(VisibleAnywhere)
	TArray<AActor*> enemyArray;
};



