

#include "BasePlayer.h"
#include "SeaWater.h"
#include "Components/AudioComponent.h"

ABasePlayer::ABasePlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	Mesh->SetSimulatePhysics(false);
	

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Mesh);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArm);

	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Component"));
	AudioComponent->SetupAttachment(Mesh);
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
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveUp", this, &ABasePlayer::MoveUp);
	InputComponent->BindAxis("MoveRight", this, &ABasePlayer::MoveRight);
	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ABasePlayer::Jump);

	OnActorBeginOverlap.AddDynamic(this, &ABasePlayer::OnOverlappedByWater);
	SpawnInTheBegin();
}

void ABasePlayer::SpawnInTheBegin()
{
	SetActorLocation(FVector(650, -2610, 352));
}

void ABasePlayer::MoveUp(float Value)
{
	FVector ForceVector = FVector(1, 0, 0) * MovementForce * Value;
	Mesh->AddForce(ForceVector);
}

void ABasePlayer::MoveRight(float Value)
{
	FVector ForceVector = FVector(0, 1, 0) * MovementForce * Value;
	Mesh->AddForce(ForceVector);
}

void ABasePlayer::Jump()
{
	FVector JumpVector = FVector(0, 0, 1) * JumpImpulse;
	Mesh->AddImpulse(JumpVector);
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

