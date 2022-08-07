// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COINCOLLECTOR_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHealthComponent();
	UFUNCTION()
	int32 GetHealth();
	void HeathDecrement();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health")
	int32 CurrentHealth=0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health")
	int32 MaxHealth=3;
protected:
	virtual void BeginPlay() override;


};
