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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    void ReportDeath();

    virtual void FighterTick( float DeltaTime ) {};

    class USkeletalMeshComponent* m_mesh_warrior;
    class AFightReporter* m_o_reporter;

    TSubclassOf<AFightActor> archarClass, riderClass, shieldClass;
public:	
	// Called every frame
	void Tick(float DeltaTime) override final;

};
