// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldMapMode.h"
#include "Huds/WorldMapHud.h"
#include "Level/WorldMapViewer.h"
#include "Controllers/WorldMapController.h"

#include "FistWorldInstance.h"
#include "Kismet/GameplayStatics.h"

#include "Static/Lang/TacticsNotice.h"

#include "Story/Kingdom.h"
#include "Story/Town.h"
#include "Story/Warrior.h"

AWorldMapMode::AWorldMapMode()
{
    HUDClass = AWorldMapHud::StaticClass();
    DefaultPawnClass = AWorldMapViewer::StaticClass();
    PlayerControllerClass = AWorldMapController::StaticClass();
}

struct townrec
{
    UKingdom* kingdom;
    UTown* town;
    TArray<UWarrior*> warriors;
};

#define STATISTICS_WARRIOR do {                 \
    warrior = rec.warriors.Pop();               \
    int cangivesoldier = warrior->GetMaxSoldierNumber() - warrior->GetSoldierNumber();  \
    int gived = 0;                              \
    if( rec.town->GetSoldierNumber() > 0 )      \
    { /* give soldier to warrior */ }           \
    cangivesoldier -= gived;                    \
    needsoldier += cangivesoldier;              \
} while( false )


bool RoundAi( townrec rec )
{
    int needsoldier = 0;
    UWarrior* warrior;
    while( (rec.warriors.Num() > 0) && ( rec.town->GetMoney() > 20 )    // 20 -> agriculture develop cost
        && (rec.town->GetAgricultureDevelopment().GetPercent() < 0.8) )
    {
        STATISTICS_WARRIOR;
        //  create and excute a agriculture develop task with warrior
    }
    while( (rec.warriors.Num() > 0) && (rec.town->GetMoney() > 20)    // 20 -> business develop cost
        && (rec.town->GetBusinessDevelopment().GetPercent() < 0.8) )
    {
        STATISTICS_WARRIOR;
        //  create and excute a business develop task with warrior
    }
    while( (rec.warriors.Num() > 0) && (rec.town->GetMoney() > 20)    // 20 -> agriculture develop cost
        && !rec.town->GetAgricultureDevelopment().IsFull() )
    {
        STATISTICS_WARRIOR;
        //  create and excute a agriculture develop task with warrior
    }
    while( (rec.warriors.Num() > 0) && (rec.town->GetMoney() > 20)    // 20 -> agriculture develop cost
        && !rec.town->GetBusinessDevelopment().IsFull() )
    {
        STATISTICS_WARRIOR;
        //  create and excute a business develop task with warrior
    }
    if( (rec.town->GetFood() > 5000) && (needsoldier > 0) )
    {
        //  make soldier
    }
    int sumsoldier = 0;
    for( auto w : rec.warriors )
    {
        sumsoldier += w->GetSoldierNumber();
    }
    if( (rec.town->GetFood() > 3000) && (rec.warriors.Num() > 3) && ( sumsoldier > 2000 )
        && ( false /* has hostil town nearby */ ) )
    {
        //  make fight
    }

    return true;
}

bool AWorldMapMode::FinishRound()
{
    auto gi = UFistWorldInstance::GetInstance( this );
    auto pc = gi ? UGameplayStatics::GetPlayerController( this, 0 ) : nullptr;
    auto hud = pc ? Cast<AWorldMapHud>( pc->GetHUD() ) : nullptr;
    if( !hud )
    {
        return false;
    }
    hud->PopupAlert( FText::FromString( "Preparing for a new round..." ) );
    
    for( auto kingdom : gi->GetKingdomList() )
    {
        if( kingdom->IsPlayerKingdom() )
        {
            continue;
        }
        hud->PopupAlert( FText::FormatOrdered<FText>( txtKindomRound, FText::FromString( kingdom->GetKingdomName() ) ) );
        UE_LOG( LogTemp, Display, TEXT( "%s 's round" ), *(kingdom->GetKingdomName()) );
        TArray<townrec> towns;
        for( auto town : gi->GetTownList() )
        {
            if( town->GetKingdomId() != kingdom->GetKingdomId() )
            {
                continue;
            }
            townrec rec;
            rec.kingdom = kingdom;
            rec.town = town;
            for( auto warrior : gi->GetWarriorList() )
            {
                if( (warrior->GetInTown() != town->GetTownId()) || (warrior->GetStatus() != EWarriorStatus::NORMAL) )
                {
                    continue;
                }
                rec.warriors.Push( warrior );
            }
            if( rec.warriors.Num() > 0 )
            {
                towns.Push( rec );
            }
        }
        for( auto tr : towns )
        {
            if( !RoundAi( tr ) )
            {
                break;
            }
        }
    }

    // ballance town development
    gi->PlusRound();
    if( gi->GetCurrentRound() % 3 == 0 )
    {
        for( auto town : gi->GetTownList() )
        {
            town->GetAgricultureDevelopment().Ballance();
            town->GetBusinessDevelopment().Ballance();
        }
    }

    // reset warrior status
    for( auto warrior : gi->GetWarriorList() )
    {
        if( warrior->GetStatus() == EWarriorStatus::WORKING )
        {
            warrior->SetStatus( EWarriorStatus::NORMAL );
        }
    }

    if( hud )
    {
        hud->PopupAlert( FText::FromString( "New Round!" ) );
    }

    if( gi->HasFight() )
    {
        UGameplayStatics::OpenLevel( this, "LV_Fight" );
    }
    return true;
}
