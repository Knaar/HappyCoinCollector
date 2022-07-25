

#include "BasePlayer.h"
#include "SeaWater.h"
#include "Components/AudioComponent.h"

ABasePlayer::ABasePlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = BaseMesh;
	BaseMesh->SetSimulatePhysics(false);
	

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(BaseMesh);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArm);

	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Component"));
	AudioComponent->SetupAttachment(BaseMesh);
	AudioComponent->SetAutoActivate(true);
}

void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp,Warning,TEXT("Score %d"),Score);
}

void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	

	OnActorBeginOverlap.AddDynamic(this, &ABasePlayer::OnOverlappedByWater);
	SpawnInTheBegin();
}

void ABasePlayer::SpawnInTheBegin()
{
//GetWorld()->SpawnActor(this);
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
	if (Cast<ASeaWater>(OtherActor)!=nullptr)
	{
		SpawnInTheBegin();
		
	}
}

void ABasePlayer::ScoreIncrement()
{
	Score++;
}

