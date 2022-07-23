// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "SeaWater.generated.h"

UCLASS()
class COINCOLLECTOR_API ASeaWater : public AActor
{
	GENERATED_BODY()
	
public:	
	ASeaWater();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "components");
	class UStaticMeshComponent* SeaBody;
protected:
	virtual void BeginPlay() override;


};
