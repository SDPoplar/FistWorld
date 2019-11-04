// Fill out your copyright notice in the Description page of Project Settings.

#include "Kingdom.h"
#include "Story/Warrior.h"
#include "Engine/Texture2D.h"
#include "ConstructorHelpers.h"

UDataTable* UKingdom::g_lib = nullptr;
UTexture2D* UKingdom::defKingdomLogo = nullptr;
std::map<int, UTexture2D*> UKingdom::logolib;

UKingdom::UKingdom() : m_n_kingdom_id( 0 ), m_b_own_by_player( false ), m_s_name( "" )
{
    if( !g_lib )
    {
        static ConstructorHelpers::FObjectFinder<UDataTable> kingdomlib( TEXT( "/Game/Datatables/Data_KingdomBase" ) );
        g_lib = kingdomlib.Succeeded() ? kingdomlib.Object : nullptr;
    }
    if( !UKingdom::defKingdomLogo )
    {
        static ConstructorHelpers::FObjectFinder<UTexture2D> defLogo( TEXT( "/Game/Textures/KingdomLogo/Img_KingdomLogo_def" ) );
        UKingdom::defKingdomLogo = defLogo.Succeeded() ? defLogo.Object : nullptr;
        static ConstructorHelpers::FObjectFinder<UTexture2D> starlineLogo( TEXT( "/Game/Textures/KingdomLogo/Img_KingdomLogo_starline" ) );
        if( starlineLogo.Succeeded() )
        {
            UKingdom::logolib[ 3 ] = starlineLogo.Object;
        }
    }
}

bool UKingdom::SetKingdomId( int id, bool load )
{
    this->m_n_kingdom_id = id;
    if( !load )
    {
        return true;
    }
    if( !UKingdom::g_lib || !UKingdom::defKingdomLogo )
    {
        return false;
    }

    auto cursor = UKingdom::logolib.find( this->m_n_kingdom_id );
    this->m_texture_logo = (cursor == UKingdom::logolib.end())
        ? UKingdom::defKingdomLogo
        : cursor->second;

    //  todo: load data from lib
    char lineIndex[ 8 ] = "";
    sprintf( lineIndex, "%d", this->m_n_kingdom_id );
    FKingdomBaseData* line = UKingdom::g_lib->FindRow<FKingdomBaseData>( FName( "id" ), FString( lineIndex ) );
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

int UKingdom::AppendWarrior( UWarrior* warrior )
{
    this->m_has_warriors.Push( warrior );
    return this->m_has_warriors.Num();
}

UTexture2D* UKingdom::GetLogo()
{
    return this->m_texture_logo;
}
