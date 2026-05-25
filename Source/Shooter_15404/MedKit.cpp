// Fill out your copyright notice in the Description page of Project Settings.


#include "MedKit.h"

// Sets default values
AMedKit::AMedKit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMedKit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMedKit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMedKit::HealPlayer()
{

}

