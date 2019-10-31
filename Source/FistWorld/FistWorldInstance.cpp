// Fill out your copyright notice in the Description page of Project Settings.

#include "FistWorldInstance.h"
//  #include "Engine.h"
#include "Kismet/GameplayStatics.h"

UFistWorldInstance::UFistWorldInstance() : m_player_kingdom( nullptr )
{
    this->m_b_game_exists = false;      //  todo: check save file exists
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

bool UFistWorldInstance::CreateGame( int nChapterId )
{
    //TODO: create empty game and save to file
    //  this->m_b_game_exists = true;
    return this->LoadGame();
}

bool UFistWorldInstance::LoadGame()
{
    //TODO: Load game from save file

    //  if( ! savefile->exists )
    return false;

    //  if( !savefile->valid() )
    return false;

    return true;
}

bool UFistWorldInstance::HasGameLoaded( void ) const
{
    return this->m_b_game_loaded;
}
