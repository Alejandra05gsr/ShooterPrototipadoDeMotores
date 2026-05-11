// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "Shooter_15404Character.h"
#include "BehaviorTree/blackboardComponent.h"
#include "EnemyAI.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_15404_API AEnemyAI : public AAIController
{
	GENERATED_BODY()

protected:
	AShooter_15404Character* playerPawn;

	AShooter_15404Character* myCharacter; //Enemigo

	UPROPERTY(EditAnywhere)
	UBehaviorTree* enemyTree;

	virtual void BeginPlay();
	virtual void Tick(float DeltaSeconds) override;

public:
	void StartBehaviorTree(AShooter_15404Character* character);

	AShooter_15404Character* getPlayerCharacter() const { return playerPawn; };
	AShooter_15404Character* getMyCharacter() const { return myCharacter; };
	
};
