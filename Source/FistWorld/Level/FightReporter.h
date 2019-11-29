// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TickAfterTurnOn.h"
#include <map>
#include "FightReporter.generated.h"

class ActorIns
{
public:
    ActorIns( bool _alive = true, int _damage = 0, int _kill = 0 )
        : alive( _alive ), totalDamage( _damage ), totalKill( _kill ) {}
    bool alive;
    int totalDamage;
    int totalKill;
};

typedef std::map<class AFightActor*, ActorIns> amap;

UCLASS()
class FISTWORLD_API AFightReporter : public AActor, public TickAfterTurnOn
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AFightReporter();
    void AppendAttacker( class AFightActor* attacker );
    void AppendDefencer( class AFightActor* defencer );

    bool ReportDamage( class AFightActor* reporter, class AFightActor* damageMaker, int damage, bool killed );
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    bool hasActorAlive( const amap& holder ) const noexcept;

    void CheckResult();

    amap m_map_attacker, m_map_defencer;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
