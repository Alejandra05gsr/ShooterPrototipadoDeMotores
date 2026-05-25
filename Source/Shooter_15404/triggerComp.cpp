// Fill out your copyright notice in the Description page of Project Settings.


#include "triggerComp.h"

UtriggerComp::UtriggerComp()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UtriggerComp::BeginPlay()
{
	Super::BeginPlay();
	
	
	if (moveActor)
	{
		moveComponent = moveActor->FindComponentByClass<UMove>();
	}
	if (IsPreshurePlate)
	{
		OnComponentBeginOverlap.AddDynamic(this, &UtriggerComp::OnOverlapBegin);
		OnComponentEndOverlap.AddDynamic(this, &UtriggerComp::OnOverlapEnd);
	}

	if (IsMedKit && IsTriggered)
	{
		player->HealingPlayer(medKit);
	}

}

void UtriggerComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UtriggerComp::trigger(bool triggerValue)
{
	IsTriggered = triggerValue;
	if (moveComponent)
	{
		moveComponent->SetShouldMove(IsTriggered);
	}
	
}

void UtriggerComp::OnOverlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	if (otherActor && otherActor->ActorHasTag("Player"))
	{
		if (!IsTriggered)
		{
			trigger(true);
		}
	}
}

void UtriggerComp::OnOverlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
	if (otherActor && otherActor->ActorHasTag("Player"))
	{
		if (IsTriggered)
		{
			trigger(false);
		}
	}
}
