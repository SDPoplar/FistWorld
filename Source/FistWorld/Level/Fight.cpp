// Copyright 2019

#include "Fight.h"
#include "Story/Kingdom.h"
#include "Story/Town.h"
#include "Story/Warrior.h"
#include "Level/FightReporter.h"

UFight::UFight( UKingdom* attackerKingdom, UTown* fromTown, UTown* toTown ) : m_o_attacker_kingdom( attackerKingdom ),
    m_o_from_town( fromTown ), m_o_to_town( toTown )
{}

bool UFight::IsValid( void ) const noexcept
{
    return true
        && this->m_o_attacker_kingdom
        && this->m_o_from_town
        && this->m_o_to_town
        && this->m_attacker_warriors.Num()
        && true;
}

int UFight::AppendAttackerWarrior( UWarrior* warrior )
{
    this->m_attacker_warriors.AddUnique( warrior );
    return this->m_attacker_warriors.Num();
}

TArray<UWarrior*>& UFight::GetAttackerWarriors()
{
    return this->m_attacker_warriors;
}

bool UFight::IsPlayerAttack() const noexcept
{
    return this->m_o_attacker_kingdom->IsPlayerKingdom();
}

bool UFight::IsPlayerDefence() const noexcept
{
    return this->m_o_to_town->OwnByPlayer();
}

bool UFight::IsPlayerFight() const noexcept
{
    return this->IsPlayerAttack() || this->IsPlayerDefence();
}

UTown* UFight::GetTargetTown() const noexcept
{
    return this->m_o_to_town;
}

UTown* UFight::GetFromTown() const noexcept
{
    return this->m_o_from_town;
}

UKingdom* UFight::GetAttackerKingdom() const noexcept
{
    return this->m_o_attacker_kingdom;
}

//  =====================   Ins methods  =================================

UFightIns& UFightIns::operator=( UFight* fight )
{
    this->m_o_attacker_kingdom = fight->GetAttackerKingdom();
    this->m_o_from_town = fight->GetFromTown();
    this->m_o_to_town = fight->GetTargetTown();
    for( auto item : fight->GetAttackerWarriors() )
    {
        this->m_attacker_warriors.Add( item );
    }
    
    return *this;
}

TArray<UWarrior*>& UFightIns::GetDefencerWarriors()
{
    return this->m_defencer_warriors;
}

void UFightIns::SetDefencer( TArray<UWarrior*> defencers )
{
    this->m_defencer_warriors = defencers;
}

void UFightIns::BindReporter( AFightReporter* reporter )
{
    this->m_o_reporter = reporter;
}

void UFightIns::ReleaseReporter( void )
{
    if( this->m_o_reporter && this->m_o_reporter->IsValidLowLevelFast() )
    {
        this->m_o_reporter->ReleaseAlive();
    }
}
