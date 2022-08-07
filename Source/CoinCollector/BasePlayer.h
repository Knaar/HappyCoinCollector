#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "HealthComponent.h"
#include "BasePlayer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerGameOver,APawn*,Actor);

UCLASS()
class COINCOLLECTOR_API ABasePlayer : public APawn
{
	GENERATED_BODY()

public:
	ABasePlayer();

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components")
	class UStaticMeshComponent *BaseMesh;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components")
	class USpringArmComponent *SpringArm;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="Components")
	class UCameraComponent *CameraComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Component")
	class UAudioComponent* AudioComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Component")
	class UAudioComponent* AudioComponentMainGameplay;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components")
	float MovementForce=100000;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	int32 Score=0;
	
	class UHealthComponent*HealthComponent;
	
	UPROPERTY(BlueprintAssignable)
	FPlayerGameOver OnPlayerGameOver;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SpawnInTheBegin();
	void SpawnDaisabledPhysics();
	UFUNCTION()
	void MoveUp(float Value);
	UFUNCTION()
	void MoveRight(float Value);

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float JumpImpulse=100000;

	void Jump();
	UFUNCTION()
	void OnOverlappedByWater(AActor* OvelappedActor, AActor* OtherActor);

	void ScoreIncrement();
};
