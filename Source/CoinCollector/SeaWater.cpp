// Fill out your copyright notice in the Description page of Project Settings.


#include "SeaWater.h"

ASeaWater::ASeaWater()
{
	PrimaryActorTick.bCanEverTick = true;
	SeaBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SeaBody"));
	RootComponent = SeaBody;
}

void ASeaWater::BeginPlay()
{
	Super::BeginPlay();
	
}


