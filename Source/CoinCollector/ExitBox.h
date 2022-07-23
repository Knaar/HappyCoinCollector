// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExitBox.generated.h"

UCLASS()
class COINCOLLECTOR_API AExitBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExitBox();

	FTimerHandle TimerHamdle;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Component")
	class UBoxComponent*TrigerBoxComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Component")
	class UAudioComponent*AudioComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Component")
	class ABasePlayer* PlayerPawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Component")
	FName LoadLevelName;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlap(AActor*ExitBoxActor,AActor*OtherActor);

	void NewGame();
};
