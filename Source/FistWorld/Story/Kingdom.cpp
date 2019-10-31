// Fill out your copyright notice in the Description page of Project Settings.

#include "Kingdom.h"
#include "Story/Warrior.h"

UDataTable* UKingdom::g_lib = nullptr;

UKingdom::UKingdom() : m_n_kingdom_id( 0 ), m_b_own_by_player( false )
{
    if( !g_lib )
    {

    }
}

bool UKingdom::SetKingdomId( int id, bool load )
{
    this->m_n_kingdom_id = id;
    if( !load )
    {
        return true;
    }

    //  todo: load data from lib
    return true;
}

int UKingdom::GetKingdomId() const
{
    return this->m_n_kingdom_id;
}

bool UKingdom::IsPlayerKingdom() const
{
    return this->m_b_own_by_player;
}

void UKingdom::SetPlayerKingdom( const bool isPlayerKingdom )
{
    this->m_b_own_by_player = isPlayerKingdom;
}

int UKingdom::AppendWarrior( UWarrior* warrior )
{
    this->m_has_warriors.Push( warrior );
    return this->m_has_warriors.Num();
}
