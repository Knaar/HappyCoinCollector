#include "HealthComponent.h"
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

int32 UHealthComponent::GetHealth()
{
	return CurrentHealth;
}

void UHealthComponent::HeathDecrement()
{
	CurrentHealth--;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth=MaxHealth;
	
}


