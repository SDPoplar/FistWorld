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
    ActorIns( bool _alive = true, float _damage = 0, int _kill = 0 )
        : alive( _alive ), totalDamage( _damage ), totalKill( _kill ),
        warrior( nullptr ) {}
    bool alive;
    float totalDamage;
    int totalKill;
    class UWarrior* warrior;

    FText ToText() const noexcept;
    int GetKillNum() const noexcept;
    int GetDamageIntval() const noexcept;
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

    bool ReportDamage( class AFightActor* reporter, class AFightActor* damageMaker, float damage, bool killed );
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    bool hasActorAlive( const amap& holder ) const noexcept;

    void CheckResult();
    void ReleaseAlive();

    amap m_map_attacker, m_map_defencer;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
