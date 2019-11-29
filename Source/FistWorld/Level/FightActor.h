// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TickAfterTurnOn.h"
#include "Story/Warrior.h"
#include <map>
#include "FightActor.generated.h"

UCLASS()
class FISTWORLD_API AFightActor : public AActor, public TickAfterTurnOn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFightActor();

    virtual void LoadWarrior( UWarrior* warrior );
    static AFightActor* SpawnWarrior( UWarrior* warrior, UWorld* inWorld );
    void BindReporter( class AFightReporter* reporter );
    void SetNearest( AFightActor* nearset );

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    virtual void WantMoveTo( AFightActor* targetActor );
    virtual void WantAttack( AFightActor* targetActor );

    void ReportDeath();

    virtual void FighterTick( float DeltaTime ) {};

    class USkeletalMeshComponent* m_mesh_warrior;
    //  class UMovementComponent* m_comp_actor_move;
    class AFightReporter* m_o_reporter;

    //  UPROPERTY( EditDefaultsOnly )
    class UNavMovementComponent* m_comp_nav_move;

    TSubclassOf<AFightActor> archarClass, riderClass, shieldClass;
    float m_f_attack_range;
public:	
	// Called every frame
	void Tick(float DeltaTime) override final;

};
