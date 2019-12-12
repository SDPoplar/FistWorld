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
#include "Level/KingdomRoundAi.h"

AWorldMapMode::AWorldMapMode()
{
    HUDClass = AWorldMapHud::StaticClass();
    DefaultPawnClass = AWorldMapViewer::StaticClass();
    PlayerControllerClass = AWorldMapController::StaticClass();
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
                rec.warriors.Push( warrior );
            }
            if( rec.warriors.Num() > 0 )
            {
                towns.Push( rec );
            }
        }
        UKingdomRoundAi::Create( this, gi->GetCurrentChapter(), gi->GetCurrentRound() )
            ->BindKingdom( kingdom )->SetTownStatistics( towns )->DoRound();
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
