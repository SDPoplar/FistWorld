// Fill out your copyright notice in the Description page of Project Settings.

#include "Kingdom.h"
#include "Story/Warrior.h"
#include "Engine/Texture2D.h"

UDataTable* UKingdom::g_lib = nullptr;
UTexture2D* UKingdom::defKingdomLogo = nullptr;
std::map<int, UTexture2D*> UKingdom::logolib;

UKingdom::UKingdom() : HasMoneyAndFood(), m_n_kingdom_id( 0 ), m_s_name( "" ), m_b_own_by_player( false )
{
    UKingdom::LoadResource();
    this->m_texture_logo = UKingdom::defKingdomLogo;
}

UKingdom::~UKingdom()
{}

void UKingdom::LoadResource()
{
    if( !g_lib )
    {
        g_lib = LoadObject<UDataTable>( nullptr, TEXT( "DataTable'/Game/Datatables/Data_KingdomBase.Data_KingdomBase'" ) );
    }
    if( !UKingdom::defKingdomLogo )
    {
        UKingdom::defKingdomLogo = LoadObject<UTexture2D>( nullptr,
            TEXT( "Texture2D'/Game/Textures/KingdomLogo/Img_KingdomLogo_def.Img_KingdomLogo_def'" ) );
    }
}

bool UKingdom::SetKingdomId( int id, bool load )
{
    this->m_n_kingdom_id = id;
    if( !load )
    {
        return true;
    }
    if( ( id == 0 ) || !UKingdom::g_lib || !UKingdom::defKingdomLogo )
    {
        return false;
    }

    auto cursor = UKingdom::logolib.find( this->m_n_kingdom_id );
    this->m_texture_logo = (cursor == UKingdom::logolib.end())
        ? UKingdom::defKingdomLogo
        : cursor->second;

    //  todo: load data from lib
    char lineIndex[ 8 ] = "";
    sprintf_s( lineIndex, 8, "%d", this->m_n_kingdom_id );
    FKingdomBaseData* line = UKingdom::g_lib->FindRow<FKingdomBaseData>( lineIndex , "id" );
    if( !line )
    {
        return false;
    }
    this->m_s_name = line->name;

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

FString UKingdom::GetKingdomName( void ) const
{
    return this->m_s_name;
}

UTexture2D* UKingdom::GetLogo() const
{
    return this->m_texture_logo;
}

UTexture2D* UKingdom::GetDefaultLogo()
{
    UKingdom::LoadResource();
    return UKingdom::defKingdomLogo;
}

int UKingdomIns::GetKingdomId() const
{
    return UKingdom::GetKingdomId();
}

bool UKingdomIns::IsPlayerKingdom() const
{
    return UKingdom::IsPlayerKingdom();
}

void UKingdomIns::SetPlayerKingdom( const bool isPlayerKingdom )
{
    UKingdom::SetPlayerKingdom( isPlayerKingdom );
}

FString UKingdomIns::GetKingdomName() const
{
    return UKingdom::GetKingdomName();
}

UTexture2D* UKingdomIns::GetLogo() const
{
    return UKingdom::GetLogo();
}

UKingdomIns& UKingdomIns::operator=( const UKingdom* obj )
{
    this->m_b_own_by_player = obj->IsPlayerKingdom();
    this->m_n_kingdom_id = obj->GetKingdomId();
    this->m_s_name = obj->GetKingdomName();
    this->m_texture_logo = obj->GetLogo();
    return *this;
}
