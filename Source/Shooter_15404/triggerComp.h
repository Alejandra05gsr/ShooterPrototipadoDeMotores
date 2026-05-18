// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Move.h"
#include "triggerComp.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHOOTER_15404_API UtriggerComp : public UBoxComponent
{
	GENERATED_BODY()

public:
	UtriggerComp();

protected:
	virtual void BeginPlay() override;

public:

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void trigger(bool triggerValue);

	UPROPERTY(EditAnywhere)
	bool IsPreshurePlate = false;

	UPROPERTY(VisibleAnywhere)
	bool IsTriggered = false;

	UPROPERTY(EditAnywhere)
	AActor* moveActor;

	UMove* moveComponent;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* overlappedComp, AActor* otherActor,
		UPrimitiveComponent* otherComp, int32 otherBodyIndex,
		bool bFromSweep, const FHitResult& sweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* overlappedComp, AActor* otherActor,
		UPrimitiveComponent* otherComp, int32 otherBodyIndex);
};
