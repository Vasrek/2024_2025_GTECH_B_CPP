#include "Pawns/BasePawn.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Projectile/Projectile.h"

ABasePawn::ABasePawn()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	RootComponent = BoxComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base mesh"));
	BaseMesh->SetupAttachment(BoxComp);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnLocation = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Projectile Location"));
	ProjectileSpawnLocation->SetupAttachment(TurretMesh);

}

void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABasePawn::RotateTurret(FVector LookAtTarget)
{
	FVector ToTarget = LookAtTarget - TurretMesh->GetComponentLocation();
	FRotator LookAtRotation =  FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);

	TurretMesh->SetWorldRotation(
		FMath::RInterpTo(
			TurretMesh->GetComponentRotation(),
			LookAtRotation,
			UGameplayStatics::GetWorldDeltaSeconds(this),
			InterpSpeed));
}

void ABasePawn::Fire()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Fire");

	FVector ProjectileSpawnPointLocation = ProjectileSpawnLocation->GetComponentLocation();
	FRotator ProjectileSpawnPointRotation = ProjectileSpawnLocation->GetComponentRotation();
	FVector Scale = ProjectileScale;
	FTransform SpawnProjectileTransform(ProjectileSpawnPointRotation, ProjectileSpawnPointLocation, Scale);

	if (ProjectileClass != nullptr)
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, SpawnProjectileTransform);
		Projectile->SetOwner(this);
	}
}


