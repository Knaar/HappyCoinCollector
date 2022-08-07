// Fill out your copyright notice in the Description page of Project Settings.


#include "ExitBox.h"
#include "Components/BoxComponent.h"
#include "Components/AudioComponent.h"
#include "BasePlayer.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AExitBox::AExitBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	USceneComponent* SceneComponent=CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent=SceneComponent;

	TrigerBoxComponent=CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	TrigerBoxComponent->SetupAttachment(SceneComponent);

	AudioComponent=CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Component"));
	AudioComponent->SetupAttachment(SceneComponent);
	AudioComponent->SetAutoActivate(false);

	OnActorBeginOverlap.AddDynamic(this, &AExitBox::OnOverlap);
}

// Called when the game starts or when spawned
void AExitBox::BeginPlay()
{
	Super::BeginPlay();
	
}

void AExitBox::OnOverlap(AActor* ExitBoxActor, AActor* OtherActor)
{
	
	PlayerPawn=Cast<ABasePlayer>(OtherActor);
	if ((PlayerPawn->Score) >= 1) {
		AudioComponent->Play();
		PlayerPawn->Score=0;
		GetWorld()->GetTimerManager().SetTimer(TimerHamdle,this, &AExitBox::NewGame, 5, false, 7);
	}
	
	
	
}

void AExitBox::NewGame()
{
	UGameplayStatics::OpenLevel(GetWorld(),LoadLevelName);

}
