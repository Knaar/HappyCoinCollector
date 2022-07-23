// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCoin.h"
#include "BasePlayer.h"
#include "Components/AudioComponent.h"

// Sets default values
ABaseCoin::ABaseCoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>("CoinMesh");
	CoinMesh->SetupAttachment(Root);
	CoinMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	RotationRate = 100;

	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Component"));
	AudioComponent->SetupAttachment(Root);
	AudioComponent->SetAutoActivate(false);

	OnActorBeginOverlap.AddDynamic(this, &ABaseCoin::OnOverlap);
}

// Called when the game starts or when spawned
void ABaseCoin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCoin::Tick(float DeltaTime)
{
	AddActorLocalRotation(FRotator(0, RotationRate * DeltaTime, 0));
}

void ABaseCoin::DeathTimerComplete()
{
	Destroy();
	PlayerPawn->ScoreIncrement();
	AudioComponent->Play();
}

void ABaseCoin::PlayCustomDeath()
{
	RotationRate = 1500;
	GetWorldTimerManager().SetTimer(DeathTimerHandle, this, &ABaseCoin::DeathTimerComplete, 0.5f, false);
}

void ABaseCoin::OnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	
	PlayerPawn= Cast<ABasePlayer>(OtherActor);
	
	if(IsValid(PlayerPawn)){

		PlayCustomDeath();
		
	}
	
}

void ABaseCoin::ScoreAdd()
{
	PlayerPawn = Cast<ABasePlayer>(this);
	
}
