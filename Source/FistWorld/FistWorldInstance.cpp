// Fill out your copyright notice in the Description page of Project Settings.

#include "FistWorldInstance.h"
//  #include "Engine.h"
#include "FistWorldSave.h"
#include "Kismet/GameplayStatics.h"
#include "Story/Warrior.h"
#include "Story/Kingdom.h"
#include "Story/Town.h"

UFistWorldInstance::UFistWorldInstance() : m_player_kingdom( nullptr )
{
    this->LoadGame();
}

UFistWorldInstance* UFistWorldInstance::GetInstance( const UObject* getter )
{
    return Cast<UFistWorldInstance>( UGameplayStatics::GetGameInstance( getter ) );
}

UKingdom* UFistWorldInstance::GetMyKingdom() const
{
    return this->m_player_kingdom;
}

bool UFistWorldInstance::HasGame() const
{
    return this->m_b_game_exists;
}

bool UFistWorldInstance::LoadGame()
{
    //TODO: Load game from save file
    auto save = UFistWorldSave::LoadSave();
    if( !save )
    {
        this->m_b_game_exists = false;
        return false;
    }

    for( auto item : save->kingdoms )
    {
        auto ins = NewObject<UKingdom>();
        ins->SetKingdomId( item.KingdomId, true );
        ins->SetPlayerKingdom( item.IsPlayerKingdom );
        this->m_kingdoms.Push( ins );
        if( item.IsPlayerKingdom )
        {
            this->m_player_kingdom = ins;
        }
    }

    for( auto item : save->warriors )
    {
        auto ins = NewObject<UWarrior>();
        
        this->m_warriors.Push( ins );
    }

    for( auto item : save->towns )
    {
        auto ins = NewObject<UTown>();
        ins->SetTownId( item.TownId, true );
        ins->SetOwnerKingdom( item.KingdomId );
        this->m_towns.Push( ins );
    }

    return true;
}

bool UFistWorldInstance::HasGameLoaded( void ) const
{
    return !!this->m_player_kingdom;
}

bool UFistWorldInstance::IsPlayerKingdom( int kingdomId ) const noexcept
{
    return this->m_player_kingdom ? ( this->m_player_kingdom->GetKingdomId() == kingdomId ) : false;
}
