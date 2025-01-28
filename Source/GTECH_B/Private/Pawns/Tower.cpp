#include "Pawns/Tower.h"
#include "Pawns/Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::BeginPlay()
{
	Super::BeginPlay();

	PlayerTank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	
}


void ATower::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (PlayerTank)
	{
		float Distance = FVector::Dist(GetActorLocation(), PlayerTank->GetActorLocation());
		if (Distance <= FireRange)
		{
			RotateTurret(PlayerTank->GetActorLocation());
		}
	}
	
}