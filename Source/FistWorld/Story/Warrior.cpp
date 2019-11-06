// Fill out your copyright notice in the Description page of Project Settings.

#include "Warrior.h"
#include "UObject/ConstructorHelpers.h"

UDataTable* UWarrior::g_lib = nullptr;

UWarrior::UWarrior() : m_n_id( 0 ), m_s_name( "" ), m_n_kingdom( 0 ), m_n_in_town( 0 ), m_n_level( 0 ), m_n_exp( 0 ),
    m_n_soldier_num( 0 ), m_e_status( EWarriorStatus::NORMAL )
{
    if( !UWarrior::g_lib )
    {
        static ConstructorHelpers::FObjectFinder<UDataTable> warriorlib( TEXT( "/Game/Datatables/Data_WarriorBase" ) );
        UWarrior::g_lib = warriorlib.Succeeded() ? warriorlib.Object : nullptr;
    }
}

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
