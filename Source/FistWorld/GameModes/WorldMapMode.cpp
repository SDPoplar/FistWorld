// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldMapMode.h"
#include "Huds/WorldMapHud.h"
#include "Level/WorldMapViewer.h"
#include "Controllers/WorldMapController.h"

#include "FistWorldInstance.h"
#include "Kismet/GameplayStatics.h"

#include "Static/Lang/WorldMessage.h"

#include "Story/Kingdom.h"
#include "Story/Town.h"
#include "Story/Warrior.h"

AWorldMapMode::AWorldMapMode()
{
    HUDClass = AWorldMapHud::StaticClass();
    DefaultPawnClass = AWorldMapViewer::StaticClass();
    PlayerControllerClass = AWorldMapController::StaticClass();
}

void AWorldMapMode::StartPlay()
{
    Super::StartPlay();

    this->CheckKingdomAlive();
}

TArray<FTownStatistics> AWorldMapMode::GetTownStaticsByKingdom( UFistWorldInstance* gi, UKingdom* kingdom, bool shouldHaveWarrior )
{
    TArray<FTownStatistics> towns;
    for( auto town : gi->GetTownList() )
    {
        if( town->GetKingdomId() != kingdom->GetKingdomId() )
        {
            continue;
        }
        FTownStatistics rec( town );
        for( auto warrior : gi->GetWarriorList() )
        {
            if( (warrior->GetInTown() != town->GetTownId()) || (warrior->GetStatus() != EWarriorStatus::NORMAL) )
            {
                continue;
            }
        }
        if( !shouldHaveWarrior ||(  rec.warriors.Num() > 0 ) )
        {
            towns.Push( rec );
        }
    }
    return towns;
}

bool AWorldMapMode::FinishRound()
{
    auto gi = UFistWorldInstance::GetInstance( this );
    auto pc = gi ? UGameplayStatics::GetPlayerController( this, 0 ) : nullptr;
    auto hud = pc ? Cast<AWorldMapHud>( pc->GetHUD() ) : nullptr;

    gi->PlusRound();

    for( auto kingdom : gi->GetKingdomList() )
    {
        if( kingdom->IsPlayerKingdom() )
        {
            continue;
        }
        hud && hud->PopupAlert( FText::FormatOrdered<FText>( txtKindomRound, FText::FromString( kingdom->GetKingdomName() ) ) );
        
        auto ai = UKingdomRoundAi::Create( this, gi->GetCurrentChapter(), gi->GetCurrentRound() );
        if( ai )
        {
            ai->BindKingdom( kingdom )->SetTownStatistics( this->GetTownStaticsByKingdom( gi, kingdom, true ) )->DoRound();
        }
    }

    this->TownBallance( gi );

    // reset warrior status
    for( auto warrior : gi->GetWarriorList() )
    {
        if( warrior->GetStatus() == EWarriorStatus::WORKING )
        {
            warrior->SetStatus( EWarriorStatus::NORMAL );
        }
    }

    hud && hud->PopupAlert( txtNewRoundStart );

    if( gi->HasFight() )
    {
        UGameplayStatics::OpenLevel( this, "LV_Fight" );
    }
    return true;
}

void AWorldMapMode::TownBallance( UFistWorldInstance* gi )
{
    if( gi->GetCurrentRound() % 3 == 0 )
    {
        for( auto town : gi->GetTownList() )
        {
            town->GetAgricultureDevelopment().Ballance();
            town->GetBusinessDevelopment().Ballance();
        }
    }
    for( auto kingdom : gi->GetKingdomList() )
    {
        for( auto statis : this->GetTownStaticsByKingdom( gi, kingdom, false ) )
        {
            int sumsoldier = 0;
            for( auto warrior : statis.warriors )
            {
                sumsoldier += warrior->GetSoldierNumber();
            }
            statis.town->IncreaseFood( ( sumsoldier + statis.town->GetSoldierNumber() ) / -10 );
            if( statis.town->GetFood() )
            {
                continue;
            }
            statis.town->SetSoldierNumber( statis.town->GetSoldierNumber() / 2 );
            for( auto warrior : statis.warriors )
            {
                warrior->SetSoldierNumber( warrior->GetSoldierNumber() / 2 );
            }
        }
    }
}

bool HasTown( int kingdomId, UFistWorldInstance* gi )
{
    for( auto town : gi->GetTownList() )
    {
        if( town->GetKingdomId() == kingdomId )
        {
            return true;
        }
    }
    return false;
}

void AWorldMapMode::CheckKingdomAlive()
{
    auto gi = UFistWorldInstance::GetInstance( this );
    int alive = 0;
    auto pc = UGameplayStatics::GetPlayerController( this, 0 );
    auto hud = pc ? Cast<AWorldMapHud>( pc->GetHUD() ) : nullptr;
    //  TArray<UKingdom*> died;     //  use this if the follow 'for' crashes on 'Remove'
    for( auto kingdom : gi->GetKingdomList() )
    {
        if( HasTown( kingdom->GetKingdomId(), gi ) )
        {
            alive++;
            continue;
        }
        if( kingdom->IsPlayerKingdom() )
        {
            hud->PopupGameResult( false );
            return;
        }

        hud->PopupAlert( FText::FormatOrdered<FText>( txtKingdomDie, FText::FromString( kingdom->GetKingdomName() ) ) );
        gi->GetKingdomList().Remove( kingdom );
        //  died.Add( kingdom );
    }
    /*
    for( auto kingdom : died )
    {
        hud->PopupAlert( FText::FormatOrdered<FText>( txtKingdomDie, FText::FromString( kingdom->GetKingdomName() ) ) );
        gi->GetKingdomList().Remove( kingdom );
    }
    */
    if( alive <= 1 )
    {
        hud->PopupGameResult( true );
    }
}
