// Copyright 2019

#include "Fight.h"
#include "Story/Kingdom.h"
#include "Story/Town.h"
#include "Story/Warrior.h"

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
