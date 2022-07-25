// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class COINCOLLECTOR_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
public:

	AMyPlayerController();
	virtual void SetupInputComponent()override;
	UPROPERTY()
	class ABasePlayer* PlayerPawn;

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void MoveUp(float Value);

	UFUNCTION()
	void MoveRight(float Value);

	UFUNCTION()
	void Jump();


};
