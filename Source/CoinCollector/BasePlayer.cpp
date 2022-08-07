

#include "BasePlayer.h"
#include "SeaWater.h"
#include "Components/AudioComponent.h"
#include "HealthComponent.h"
#include "Components/ForceFeedbackComponent.h"

ABasePlayer::ABasePlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = BaseMesh;
	BaseMesh->SetSimulatePhysics(true);
	


	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(BaseMesh);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArm);

	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Component"));
	AudioComponent->SetupAttachment(BaseMesh);
	AudioComponent->SetAutoActivate(false);

	AudioComponentMainGameplay = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Component Main Component"));
	AudioComponentMainGameplay->SetupAttachment(BaseMesh);
	AudioComponentMainGameplay->SetAutoActivate(false);

	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
}

void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();

}

void ABasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Score %d"), Score);
}

void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{


	OnActorBeginOverlap.AddDynamic(this, &ABasePlayer::OnOverlappedByWater);
	SpawnInTheBegin();
}

void ABasePlayer::SpawnInTheBegin()
{
	BaseMesh->CreatePhysicsState(true);
	SetActorLocation(FVector(650, -2610, 352));
}

void ABasePlayer::SpawnDaisabledPhysics()
{
	SetActorLocation(FVector(650, -2610, 352));
}

void ABasePlayer::MoveUp(float Value)
{
	if (BaseMesh) {
		FVector ForceVector = FVector(1, 0, 0) * MovementForce * Value;
		BaseMesh->AddForce(ForceVector);

	}

}

void ABasePlayer::MoveRight(float Value)
{
	if (BaseMesh)
	{
		FVector ForceVector = FVector(0, 1, 0) * MovementForce * Value;
		BaseMesh->AddForce(ForceVector);
	}

}

void ABasePlayer::Jump()
{
	if (BaseMesh)
	{
		FVector JumpVector = FVector(0, 0, 1) * JumpImpulse;
		BaseMesh->AddImpulse(JumpVector);
	}
}

void ABasePlayer::OnOverlappedByWater(AActor* OvelappedActor, AActor* OtherActor)
{
	if (Cast<ASeaWater>(OtherActor) != nullptr)
	{
		BaseMesh->DestroyPhysicsState();

		HealthComponent->HeathDecrement();
		if (HealthComponent->GetHealth() > 0)
		{
			SpawnInTheBegin();
		}		
		else {
			//SpawnInTheBegin();
			//BaseMesh->Deactivate();
			BaseMesh->DestroyPhysicsState();
			OnPlayerGameOver.Broadcast(this);
		}

	}
}

void ABasePlayer::ScoreIncrement()
{
	Score++;
}

