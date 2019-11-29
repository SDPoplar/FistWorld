// Copyright 2019

#include "FightReporter.h"
#include "Level/FightActor.h"
#include "GameModes/TownFightMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFightReporter::AFightReporter() : TickAfterTurnOn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFightReporter::BeginPlay()
{
	AActor::BeginPlay();
	
}

// Called every frame
void AFightReporter::Tick(float DeltaTime)
{
	AActor::Tick(DeltaTime);
    CHECK_TICK_TURNON_NORET;

    for( auto item : this->m_map_attacker )
    {
        AFightActor* t = nullptr;
        float dis = -1;
        for( auto target : this->m_map_defencer )
        {
            if( !target.second.alive )
            {
                continue;
            }
            float cdis = target.first->GetDistanceTo( item.first );
            if( (dis < 0) || dis > cdis )
            {
                t = target.first;
                dis = cdis;
            }
        }
        if( t )
        {
            item.first->SetNearest( t );
        }
    }

    for( auto item : this->m_map_defencer )
    {
        AFightActor* t = nullptr;
        float dis = -1;
        for( auto target : this->m_map_attacker )
        {
            if( !target.second.alive )
            {
                continue;
            }
            float cdis = target.first->GetDistanceTo( item.first );
            if( (dis < 0) || dis > cdis )
            {
                t = target.first;
                dis = cdis;
            }
        }
        if( t )
        {
            item.first->SetNearest( t );
        }
    }

    this->CheckResult();
}

void AFightReporter::AppendAttacker( AFightActor* attacker )
{
    ActorIns empty;
    this->m_map_attacker[ attacker ] = empty;
}

void AFightReporter::AppendDefencer( AFightActor* defencer )
{
    ActorIns empty;
    this->m_map_defencer[ defencer ] = empty;
}

void AFightReporter::CheckResult()
{
    bool attackerAlive = this->hasActorAlive( this->m_map_attacker );
    bool defencerAlive = this->hasActorAlive( this->m_map_defencer );
    auto gm = ( attackerAlive && defencerAlive ) ? nullptr : Cast<ATownFightMode>( UGameplayStatics::GetGameMode( this ) );
    if( !gm )
    {
        return;
    }

    if( attackerAlive )
    {
        gm->AttackerWin();
    }
    else
    {
        gm->DefencerWin();
    }
}

bool AFightReporter::hasActorAlive( const amap& holder ) const noexcept
{
    for( auto item : this->m_map_attacker )
    {
        if( item.second.alive )
        {
            return true;
        }
    }
    return false;
}

bool AFightReporter::ReportDamage( AFightActor* reporter, AFightActor* damageMaker, int damage, bool killed )
{
    auto from = this->m_map_attacker.find( damageMaker );
    if( from == this->m_map_attacker.end() )
    {
        from = this->m_map_defencer.find( damageMaker );
        if( from == this->m_map_defencer.end() )
        {
            return false;
        }
    }
    if( !from->second.alive )
    {
        return false;
    }
    from->second.totalDamage += damage;
    if( killed )
    {
        from->second.totalKill++;
    }
    return true;
}
