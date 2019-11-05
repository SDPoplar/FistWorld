// Fill out your copyright notice in the Description page of Project Settings.

#include "Town.h"
#include "UObject/ConstructorHelpers.h"
#include "FistWorldInstance.h"

UDataTable* UTown::g_lib = nullptr;

UTown::UTown() : m_n_town_id( 0 ), m_n_own_by_kingdom( 0 ), m_s_town_name( "" )
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
    if( !UTown::g_lib )
    {
        return false;
    }
    char lineIndex[ 8 ];
    sprintf( lineIndex, "%d", this->m_n_town_id );
    FTownBaseData* data = UTown::g_lib->FindRow<FTownBaseData>( "id", lineIndex );
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
