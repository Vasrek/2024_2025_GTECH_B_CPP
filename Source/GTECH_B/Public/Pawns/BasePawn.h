#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

// LAST INCLUDE 
#include "BasePawn.generated.h"

// FORWARD DECLARATION
class UBoxComponent;
class AProjectile;

UCLASS()
class GTECH_B_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	ABasePawn();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	void RotateTurret(FVector LookAtTarget);

	UPROPERTY(EditAnywhere, Category = "Canon Properties")
	float InterpSpeed = 5.f;

	void Fire();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* BoxComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnLocation;

	UPROPERTY(EditAnywhere, Category = "Combat Properties")
	TSubclassOf<AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Combat Properties")
	FVector ProjectileScale = FVector(2.0f, 2.0f, 2.0f);

};
