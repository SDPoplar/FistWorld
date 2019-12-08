// Copyright 2019

#include "FightReporter.h"
#include "Level/FightActor.h"
#include "GameModes/TownFightMode.h"
#include "Kismet/GameplayStatics.h"
#include "Static/Lang/FightInfo.h"

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

    TArray<AFightActor*> alive_attacker, alive_defencer;
    for( auto item : this->m_map_attacker )
    {
        if( item.second.alive && item.first->IsValidLowLevelFast() )
        {
            alive_attacker.Push( item.first );
        }
    }
    for( auto item : this->m_map_defencer )
    {
        if( item.second.alive && item.first->IsValidLowLevelFast() )
        {
            alive_defencer.Push( item.first );
        }
    }
    for( auto item : this->m_map_attacker )
    {
        if( item.first->IsValidLowLevel() )
        {
            item.first->SetAliveTarget( alive_defencer );
        }
    }
    for( auto item : this->m_map_defencer )
    {
        if( item.first->IsValidLowLevelFast() )
        {
            item.first->SetAliveTarget( alive_attacker );
        }
    }

    this->CheckResult();
}

void AFightReporter::AppendAttacker( AFightActor* attacker )
{
    ActorIns empty;
    empty.warrior = attacker->GetBindedWarrior();
    this->m_map_attacker[ attacker ] = empty;
    attacker->BindReporter( this );
}

void AFightReporter::AppendDefencer( AFightActor* defencer )
{
    ActorIns empty;
    empty.warrior = defencer->GetBindedWarrior();
    this->m_map_defencer[ defencer ] = empty;
    defencer->BindReporter( this );
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

    this->TurnOff();
    TArray<FText> attack, defence;
    for( auto item : this->m_map_attacker )
    {
        attack.Add( item.second.ToText() );
    }
    for( auto item : this->m_map_defencer )
    {
        defence.Add( item.second.ToText() );
    }
    gm->FightFinish( attackerAlive, attack, defence );
}

bool AFightReporter::hasActorAlive( const amap& holder ) const noexcept
{
    for( auto item : holder )
    {
        if( item.second.alive )
        {
            return true;
        }
    }
    UE_LOG( LogTemp, Display, TEXT( "Some part is all dead" ) );
    return false;
}

bool AFightReporter::ReportDamage( AFightActor* reporter, AFightActor* damageMaker, float damage, bool killed )
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
        auto to = this->m_map_attacker.find( reporter );
        if( to == this->m_map_attacker.end() )
        {
            to = this->m_map_defencer.find( reporter );
            if( to == this->m_map_defencer.end() )
            {
                return false;
            }
        }
        to->second.alive = false;
        from->second.totalKill++;
    }
    return true;
}

void AFightReporter::ReleaseAlive()
{
    for( auto item : this->m_map_attacker )
    {
        if( item.second.alive && item.first && item.first->IsValidLowLevelFast() )
        {
            item.first->Destroy();
        }
    }
    for( auto item : this->m_map_defencer )
    {
        if( item.second.alive && item.first && item.first->IsValidLowLevelFast() )
        {
            item.first->Destroy();
        }
    }
    this->Destroy();
}

FText ActorIns::ToText() const noexcept
{
    return FText::FormatOrdered<FText, int, int>( txtFightResultTemplate,
        FText::FromString( this->warrior->GetWarriorName() ), this->GetDamageIntval(), this->GetKillNum() );
}

int ActorIns::GetKillNum() const noexcept
{
    return this->totalKill;
}

int ActorIns::GetDamageIntval() const noexcept
{
    return (int)this->totalDamage;
}
