// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "BasePlayer.h"

AMyPlayerController::AMyPlayerController()
{

}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveUp", this, &AMyPlayerController::MoveUp);
	InputComponent->BindAxis("MoveRight", this, &AMyPlayerController::MoveRight);
	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AMyPlayerController::Jump);
}



void AMyPlayerController::SetPawn(APawn* InPawn)  
{
	Super::SetPawn(InPawn);
	PlayerPawn=Cast<ABasePlayer>(InPawn);
	
}



void AMyPlayerController::MoveUp(float Value)
{
	PlayerPawn->MoveUp(Value);
}

void AMyPlayerController::MoveRight(float Value)
{
	PlayerPawn->MoveRight(Value);
}

void AMyPlayerController::Jump()
{
	PlayerPawn->Jump();
}

