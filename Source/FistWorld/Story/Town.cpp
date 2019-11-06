// Fill out your copyright notice in the Description page of Project Settings.

#include "Town.h"
#include "UObject/ConstructorHelpers.h"
#include "FistWorldInstance.h"

UDataTable* UTown::g_lib = nullptr;

UTown::UTown() : m_n_town_id( 0 ), m_s_town_name( "" ), m_n_own_by_kingdom( 0 ), m_n_money( 0 ), m_n_food( 0 ), m_n_soldier_num( 0 )
{
    if( !UTown::g_lib )
    {
        static ConstructorHelpers::FObjectFinder<UDataTable> town( TEXT( "/Game/Datatables/Data_TownBase" ) );
        if( town.Succeeded() )
        {
            UTown::g_lib = town.Object;
        }
    }
}

int UTown::GetTownId() const noexcept
{
    return this->m_n_town_id;
}

bool UTown::SetTownId( int id, bool load )
{
    this->m_n_town_id = id;
    if( !load )
    {
        return true;
    }
    if( ( id == 0 ) || !UTown::g_lib )
    {
        return false;
    }
    char lineIndex[ 8 ];
    sprintf_s( lineIndex, 8, "%d", this->m_n_town_id );
    FTownBaseData* data = UTown::g_lib->FindRow<FTownBaseData>( lineIndex, "id" );
    if( !data )
    {
        return false;
    }
    this->m_s_town_name = data->name;
    return true;
}

FString UTown::GetTownName() const noexcept
{
    return this->m_s_town_name;
}

bool UTown::OwnByPlayer() const noexcept
{
    auto gi = UFistWorldInstance::GetInstance( this );
    return ( this->m_n_own_by_kingdom && gi )
        ? gi->IsPlayerKingdom( this->m_n_own_by_kingdom ) : false;
}

void UTown::SetOwnerKingdom( int kingdomId )
{
    this->m_n_own_by_kingdom = kingdomId;
}

bool UTown::OwnByKingdom() const noexcept
{
    return !!this->m_n_own_by_kingdom;
}

int UTown::GetKingdomId() const noexcept
{
    return this->m_n_own_by_kingdom;
}

void UTown::SetMoney( int money )
{
    this->m_n_money = money;
}

int UTown::GetMoney( void ) const noexcept
{
    return this->m_n_money;
}

void UTown::SetFood( int food )
{
    this->m_n_food = food;
}

int UTown::GetFood( void ) const noexcept
{
    return this->m_n_food;
}

void UTown::SetSoldierNumber( int num )
{
    this->m_n_soldier_num = num;
}

int UTown::GetSoldierNumber( void ) const noexcept
{
    return this->m_n_soldier_num;
}
