// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TickAfterTurnOn.h"
#include "Story/Warrior.h"
#include <map>
#include "FightActor.generated.h"

UCLASS()
class FISTWORLD_API AFightActor : public APawn, public TickAfterTurnOn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFightActor();

    virtual void LoadWarrior( UWarrior* warrior );
    static AFightActor* SpawnWarrior( UWarrior* warrior, UWorld* inWorld );
    void BindReporter( class AFightReporter* reporter );
    void SetNearest( AFightActor* nearset );

    class UPawnMovementComponent* GetMovementComponent() const override;
    float GetHealthPercent() const noexcept;

    float TakeDamage( float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser ) override;
    UWarrior* GetBindedWarrior() const noexcept;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    virtual void WantMoveTo( AFightActor* targetActor );
    virtual void WantAttack( AFightActor* targetActor );
    virtual float GetAttackMagnification( EWarriorType targetType, float targetDistance ) const noexcept;

    //  void ReportDeath();

    virtual void FighterTick( float DeltaTime ) {};

    class USkeletalMeshComponent* m_mesh_warrior;
    class UFloatingPawnMovement* m_comp_pawn_move;
    class USphereComponent* m_comp_capsule;
    class UFighterNamePanelComponent* m_comp_namepanel;
    
    class AFightReporter* m_o_reporter;

    TSubclassOf<AFightActor> archarClass, riderClass, shieldClass;

    UWarrior* m_o_warrior_binded;

    float m_f_attack_range;

    float m_f_last_attack;
    float m_f_attack_cd;
    float m_f_max_health, m_f_current_health;
    float m_f_attack_base;
public:
	// Called every frame
	void Tick(float DeltaTime) override final;

};
