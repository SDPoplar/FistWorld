// Fill out your copyright notice in the Description page of Project Settings.

#include "Warrior.h"
#include "UObject/ConstructorHelpers.h"

UDataTable* UWarrior::g_lib = nullptr;

UWarrior::UWarrior() : m_n_id( 0 ), m_s_name( "" ), m_n_strong( 0 ), m_n_intel( 0 ), m_n_kingdom( 0 ), m_n_in_town( 0 ),
    m_e_status( EWarriorStatus::NORMAL ), m_n_level( 0 ), m_n_exp( 0 ), m_n_soldier_num( 0 )
{
    if( !UWarrior::g_lib )
    {
        UWarrior::g_lib = LoadObject<UDataTable>( nullptr, TEXT( "DataTable'/Game/Datatables/Data_WarriorBase.Data_WarriorBase'" ) );
    }
}

UWarrior::~UWarrior()
{}

bool UWarrior::operator==( int id )
{
    return this->m_n_id == id;
}

bool UWarrior::operator==( UWarrior* w )
{
    return *this == w->m_n_id;
}

bool UWarrior::SetWarriorId( int id, bool load )
{
    this->m_n_id = id;
    if( !load )
    {
        return true;
    }
    if( ( id == 0 ) || !UWarrior::g_lib )
    {
        return false;
    }
    char lineIndex[ 8 ];
    sprintf_s( lineIndex, 8, "%d", this->m_n_id );
    FWarriorBaseData* data = UWarrior::g_lib->FindRow<FWarriorBaseData>( lineIndex, "id" );
    if( !data )
    {
        return false;
    }
    this->m_s_name = data->name;
    this->m_n_strong = data->strong;
    this->m_n_intel = data->intel;
    UE_LOG( LogTemp, Display, TEXT( "Warrior[ID:%d] loaded Strong: %d, Intel: %d" ), this->m_n_id, this->m_n_strong, this->m_n_intel );
    return true;
}

int UWarrior::GetWarriorId() const noexcept
{
    return this->m_n_id;
}

void UWarrior::SetWarriorName( FString name )
{
    this->m_s_name = name;
}

FString UWarrior::GetWarriorName() const noexcept
{
    return this->m_s_name;
}

int UWarrior::GetStrong( void ) const noexcept
{
    return this->m_n_strong;
}

int UWarrior::GetIntel( void ) const noexcept
{
    return this->m_n_intel;
}

void UWarrior::SetBelongKingdom( int kingdomId )
{
    this->m_n_kingdom = kingdomId;
}

int UWarrior::GetBelongKingdom() const noexcept
{
    return this->m_n_kingdom;
}

void UWarrior::SetInTown( int townId )
{
    this->m_n_in_town = townId;
}

int UWarrior::GetInTown() const noexcept
{
    return this->m_n_in_town;
}

void UWarrior::SetStatus( EWarriorStatus status )
{
    this->m_e_status = status;
}

EWarriorStatus UWarrior::GetStatus() const noexcept
{
    return this->m_e_status;
}

void UWarrior::SetWarriorLevel( int level )
{
    this->m_n_level = level;
}

int UWarrior::GetWarriorLevel() const noexcept
{
    return this->m_n_level;
}

void UWarrior::SetWarriorExp( int exp )
{
    this->m_n_exp = exp;
}

int UWarrior::GetWarriorExp() const noexcept
{
    return this->m_n_exp;
}

void UWarrior::SetSoldierNumber( int num )
{
    this->m_n_soldier_num = num;
}

int UWarrior::GetSoldierNumber() const noexcept
{
    return this->m_n_soldier_num;
}

int UWarriorIns::GetWarriorId() const noexcept
{
    return UWarrior::GetWarriorId();
}

FString UWarriorIns::GetWarriorName() const noexcept
{
    return UWarrior::GetWarriorName();
}

int UWarriorIns::GetStrong() const noexcept
{
    return UWarrior::GetStrong();
}

int UWarriorIns::GetIntel( void ) const noexcept
{
    return UWarrior::GetIntel();
}

int UWarriorIns::GetBelongKingdom() const noexcept
{
    return UWarrior::GetBelongKingdom();
}

int UWarriorIns::GetInTown() const noexcept
{
    return UWarrior::GetInTown();
}

EWarriorStatus UWarriorIns::GetStatus() const noexcept
{
    return UWarrior::GetStatus();
}

int UWarriorIns::GetWarriorLevel() const noexcept
{
    return UWarrior::GetWarriorLevel();
}

int UWarriorIns::GetWarriorExp() const noexcept
{
    return UWarrior::GetWarriorExp();
}

int UWarriorIns::GetSoldierNumber() const noexcept
{
    return UWarrior::GetSoldierNumber();
}

UWarriorIns& UWarriorIns::operator=( const UWarrior* obj )
{
    this->m_n_id = obj->GetWarriorId();
    this->m_s_name = obj->GetWarriorName();
    this->m_n_kingdom = obj->GetBelongKingdom();
    this->m_n_in_town = obj->GetInTown();
    this->m_e_status = obj->GetStatus();
    this->m_n_level = obj->GetWarriorLevel();
    this->m_n_exp = obj->GetWarriorExp();
    this->m_n_soldier_num = obj->GetSoldierNumber();
    return *this;
}
