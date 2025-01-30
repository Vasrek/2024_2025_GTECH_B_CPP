#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UProjectileMovementComponent;
class UNiagaraSystem;
class USoundCue;

UCLASS()
class GTECH_B_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();
	//virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, Category = "Damage")
	float Damage = 25.f;

	UPROPERTY(EditAnywhere, Category = "Damage")
	UNiagaraSystem* ExplosionVFX;

	UPROPERTY(EditAnywhere, Category = "Damage")
	USoundCue* ExplosionSFX;

};
