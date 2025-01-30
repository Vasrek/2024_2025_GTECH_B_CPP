#include "Components/HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaken);
	
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UHealthComponent::DamageTaken(AActor* DamagedActor, float BaseDamage, const UDamageType* DamageType,
	AController* Instigator, AActor* DamageCauser)
{
	if (BaseDamage <= 0.f) return;

	CurrentHealth -= BaseDamage;
	if (CurrentHealth <= 0)
	{
		CurrentHealth = 0;
		//GetOwner()->Destroy();
	}
}
