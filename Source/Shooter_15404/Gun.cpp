// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Crea el padre inicial en el blueprint
	rootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	SetRootComponent(rootComp);


	skeletalmeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshGun" )); 
	skeletalmeshComp->SetupAttachment(rootComp ); 

	flashParticle = CreateDefaultSubobject<UNiagaraComponent>(TEXT("FlashParticle"));
	flashParticle->SetupAttachment(rootComp);



}

void AGun::PullTrigger()
{
	flashParticle->Activate(true);
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), shootSound, GetActorLocation());

	if (ownerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("Bang!!!"));
		FVector viewPointLocation;
		FRotator viewpointRotator;
		ownerController->GetPlayerViewPoint(viewPointLocation, viewpointRotator);
		//DrawDebugCamera(GetWorld(), viewPointLocation, viewpointRotator, 90, 2, FColor::Red, true);

		FVector endPoint = viewPointLocation + viewpointRotator.Vector() * maxRange;

		FHitResult hit;
		FCollisionQueryParams params;
		params.AddIgnoredActor(GetOwner());
		params.AddIgnoredActor(this);

		bool isHit = GetWorld()->LineTraceSingleByChannel(hit, viewPointLocation, endPoint, ECC_GameTraceChannel1, params);
		if (isHit)
		{
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), impactParticle, hit.ImpactPoint, hit.ImpactPoint.Rotation());
			DrawDebugSphere(GetWorld(), hit.ImpactPoint, 5, 8, FColor::Red, true);
			
			AActor* hitActor = hit.GetActor();
			if (hitActor)
			{
				UGameplayStatics::ApplyDamage(hitActor, bulletDamage, ownerController, this, UDamageType::StaticClass());
			}

		}
	}

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

