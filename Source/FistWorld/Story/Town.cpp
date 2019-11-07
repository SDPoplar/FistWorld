// Fill out your copyright notice in the Description page of Project Settings.

#include "Town.h"
#include "UObject/ConstructorHelpers.h"
#include "FistWorldInstance.h"

UDataTable* UTown::g_lib = nullptr;

UTown::UTown() : m_n_town_id( 0 ), m_s_town_name( "" ), m_n_own_by_kingdom( 0 ), m_n_money( 0 ), m_n_food( 0 ), m_n_soldier_num( 0 )
{
    if( !UTown::g_lib )
    {
        UTown::g_lib = LoadObject<UDataTable>( nullptr, TEXT( "DataTable'/Game/Datatables/Data_TownBase.Data_TownBase'" ) );
    }
}

UTown::~UTown()
{}

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

bool UTown::OwnByPlayer( const UObject* getter ) const noexcept
{
    auto gi = UFistWorldInstance::GetInstance( getter );
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

int UTownIns::GetTownId() const noexcept
{
    return UTown::GetTownId();
}

FString UTownIns::GetTownName() const noexcept
{
    return UTown::GetTownName();
}

bool UTownIns::IsOwnByPlayer() const noexcept
{
    return UTown::OwnByPlayer( this );
}

bool UTownIns::OwnByKingdom() const noexcept
{
    return UTown::OwnByKingdom();
}

int UTownIns::GetKingdomId() const noexcept
{
    return UTown::GetKingdomId();
}

int UTownIns::GetMoney() const noexcept
{
    return UTown::GetMoney();
}

int UTownIns::GetFood() const noexcept
{
    return UTown::GetFood();
}

int UTownIns::GetSoldierNumber() const noexcept
{
    return UTown::GetSoldierNumber();
}

UTownIns& UTownIns::operator=( const UTown* town )
{
    this->m_n_town_id = town->GetTownId();
    this->m_s_town_name = town->GetTownName();
    this->m_n_own_by_kingdom = town->GetKingdomId();
    this->m_n_money = town->GetMoney();
    this->m_n_food = town->GetFood();
    this->m_n_soldier_num = town->GetSoldierNumber();
    return *this;
}