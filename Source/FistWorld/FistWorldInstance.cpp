// Fill out your copyright notice in the Description page of Project Settings.

#include "FistWorldInstance.h"
//  #include "Engine.h"
#include "FistWorldSave.h"
#include "Kismet/GameplayStatics.h"
#include "Story/Warrior.h"
#include "Story/Kingdom.h"
#include "Story/Town.h"
#include "Level/Fight.h"

UFistWorldInstance::UFistWorldInstance() : m_player_kingdom( nullptr )
{
    this->m_b_game_exists = UFistWorldSave::FileExists();
    //this->LoadGame();
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

    this->m_b_game_exists = true;

    this->m_kingdoms.Empty();
    for( auto item : save->kingdoms )
    {
        auto ins = new UKingdom();
        if( !ins || !ins->SetKingdomId( item.KingdomId, true ) )
        {
            UE_LOG( LogTemp, Error, TEXT( "Failed to load kingdom[ID:%d]" ), item.KingdomId );
            continue;
        }
        ins->SetPlayerKingdom( item.IsPlayerKingdom );
        ins->SetFood( item.Food );
        ins->SetMoney( item.Money );
        this->m_kingdoms.Push( ins );
        if( item.IsPlayerKingdom )
        {
            this->m_player_kingdom = ins;
            UE_LOG( LogTemp, Display, TEXT( "Setting player kingdom: ID - %d" ), item.KingdomId );
        }
    }

    this->m_warriors.Empty();
    for( auto item : save->warriors )
    {
        auto ins = new UWarrior();
        if( !ins || !ins->SetWarriorId( item.WarriorId, true ) )
        {
            UE_LOG( LogTemp, Error, TEXT( "Failed to load warrior[ID:%d]" ), item.WarriorId );
            continue;
        }
        ins->SetBelongKingdom( item.KingdomId );
        ins->SetInTown( item.InTown );
        ins->SetStatus( item.Status );
        ins->SetWarriorLevel( item.Level );
        ins->SetWarriorExp( item.Exp );
        ins->SetSoldierNumber( item.Soldiers );
        this->m_warriors.Push( ins );
    }

    this->m_towns.Empty();
    for( auto item : save->towns )
    {
        auto ins = new UTown();
        if( !ins || !ins->SetTownId( item.TownId, true ) )
        {
            UE_LOG( LogTemp, Error, TEXT( "Failed to load town[ID:%d]" ), item.TownId );
            continue;
        }
        ins->SetOwnerKingdom( item.KingdomId );
        ins->SetMoney( item.Money );
        ins->SetFood( item.Food );
        ins->SetSoldierNumber( item.Soldiers );
        ins->GetBusinessDevelopment().SetCurrent( item.Business );
        ins->GetAgricultureDevelopment().SetCurrent( item.Agriculture );
        this->m_towns.Push( ins );
    }

    this->m_n_chapter = save->chapter;
    this->m_n_round = save->round;

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

UKingdom* UFistWorldInstance::FindKingdom( int kingdomId )
{
    for( auto item : this->m_kingdoms )
    {
        if( item->GetKingdomId() == kingdomId )
        {
            return item;
        }
    }
    return nullptr;
}

UKingdomIns* UFistWorldInstance::FindKingdomInstance( int kingdomId, UObject* getter )
{
    auto kingdom = this->FindKingdom( kingdomId );
    if( !kingdom )
    {
        return nullptr;
    }
    UKingdomIns* ins = NewObject<UKingdomIns>( getter );
    *ins = kingdom;
    return ins;
}

UTown* UFistWorldInstance::FindTown( int townId )
{
    for( auto item : this->m_towns )
    {
        if( item->GetTownId() == townId )
        {
            return item;
        }
    }
    return nullptr;
}

UTownIns* UFistWorldInstance::FindTownInstance( int townId, UObject* getter )
{
    UTown* town = this->FindTown( townId );
    if( !town )
    {
        return nullptr;
    }
    UTownIns* ins = NewObject<UTownIns>( getter );
    *ins = town;
    return ins;
}

UWarrior* UFistWorldInstance::FindWarrior( int warriorId )
{
    for( auto item : this->m_warriors )
    {
        if( *item == warriorId )
        {
            return item;
        }
    }
    return nullptr;
}

UWarriorIns* UFistWorldInstance::FindWarriorInstance( int warriorId, UObject* getter )
{
    auto warrior = this->FindWarrior( warriorId );
    if( !warrior )
    {
        return nullptr;
    }
    UWarriorIns* ins = NewObject<UWarriorIns>( getter );
    *ins = warrior;
    return ins;
}

TArray<UWarrior*>& UFistWorldInstance::GetWarriorList()
{
    return this->m_warriors;
}

TArray<UTown*>& UFistWorldInstance::GetTownList()
{
    return this->m_towns;
}

TArray<UKingdom*>& UFistWorldInstance::GetKingdomList()
{
    return this->m_kingdoms;
}

int UFistWorldInstance::CountPlayerTown() const noexcept
{
    if( !this->m_player_kingdom )
    {
        return 0;
    }
    int count = 0;
    for( auto item : this->m_towns )
    {
        if( item->GetKingdomId() == this->m_player_kingdom->GetKingdomId() )
        {
            count++;
        }
    }
    return count;
}

int UFistWorldInstance::CountPlayerWarrior() const noexcept
{
    if( !this->m_player_kingdom )
    {
        return 0;
    }
    int count = 0;
    for( auto item : this->m_warriors )
    {
        if( item->GetBelongKingdom() == this->m_player_kingdom->GetKingdomId() )
        {
            count++;
        }
    }
    return count;
}

int UFistWorldInstance::GetCurrentChapter() const noexcept
{
    return this->m_n_chapter;
}

int UFistWorldInstance::GetCurrentRound() const noexcept
{
    return this->m_n_round;
}

UKingdom* UFistWorldInstance::GetPlayerKingdom() const noexcept
{
    return this->m_player_kingdom;
}

int UFistWorldInstance::AppendFight( UFight* fight )
{
    this->m_fights.Push( fight );
    return this->m_fights.Num();
}

bool UFistWorldInstance::HasFight() const noexcept
{
    return !!this->m_fights.Num();
}

TArray<UFight*>& UFistWorldInstance::GetFightList()
{
    return this->m_fights;
}
