// Copyright 2019

#include "KingdomRoundAi.h"
#include "GameModes/WorldMapMode.h"
#include "Story/Kingdom.h"
#include "Story/Town.h"
#include "Story/Warrior.h"

#include "Tasks/TownAgricultureDevelopTask.h"
#include "Tasks/TownBusinessDevelopTask.h"
#include "Tasks/TownConscriptTask.h"

UKingdomRoundAi::UKingdomRoundAi( const FObjectInitializer& ObjectInitializer )
    : UObject( ObjectInitializer ), m_n_round( 0 ), m_o_kingdom( nullptr )
{
    this->AddToRoot();
}

UKingdomRoundAi* UKingdomRoundAi::Create( AWorldMapMode* gm, int chapter, int round )
{
    UKingdomRoundAi* ai = nullptr;
    switch( chapter )
    {
    case 1:
        ai = NewObject<UKingdomRoundAi_Chapter1>( gm );
        break;
    case 2:
        ai = NewObject<UKingdomRoundAi_Chapter2>( gm );
        break;
    case 3:
        ai = NewObject<UKingdomRoundAi_Chapter3>( gm );
        break;
    case 4:
        ai = NewObject<UKingdomRoundAi_Chapter4>( gm );
        break;
    }
    return ai ? ai->SetCurrentRound( round ) : nullptr;
}

UKingdomRoundAi* UKingdomRoundAi::SetCurrentRound( int round )
{
    this->m_n_round = round;
    return this;
}

UKingdomRoundAi* UKingdomRoundAi::BindKingdom( UKingdom* kingdom )
{
    this->m_o_kingdom = kingdom;
    return this;
}

UKingdomRoundAi* UKingdomRoundAi::SetTownStatistics( TArray<FTownStatistics> towns )
{
    this->m_arr_towns = towns;
    return this;
}

bool UKingdomRoundAi::Round()
{
    if( this->m_n_round && this->m_o_kingdom && this->m_arr_towns.Num() )
    {
        return false;
    }
    for( auto& town : this->m_arr_towns )
    {
        if( !this->TownRound( town ) )
        {
            return false;
        }
    }
    return true;
}

bool UKingdomRoundAi::DoRound()
{
    bool ret = this->Round();
    this->RemoveFromRoot();
    return ret;
}

void UKingdomRoundAi::DevTown( FTownStatistics& rec )
{
    while( (rec.warriors.Num() > 0) && (rec.town->GetAgricultureDevelopment().GetPercent() < 0.8)
        && this->AgricultureDevTask( rec.town, rec.warriors.Pop() ) );
    while( (rec.warriors.Num() > 0) && (rec.town->GetBusinessDevelopment().GetPercent() < 0.8)
        && this->BusinessDevTask( rec.town, rec.warriors.Pop() ) );
    while( (rec.warriors.Num() > 0) && !rec.town->GetAgricultureDevelopment().IsFull()
        && this->AgricultureDevTask( rec.town, rec.warriors.Pop() ) );
    while( (rec.warriors.Num() > 0) && !rec.town->GetBusinessDevelopment().IsFull()
        && this->BusinessDevTask( rec.town, rec.warriors.Pop() ) );
}

int UKingdomRoundAi::GiveSoldlier( FTownStatistics& rec )
{
    int needsoldier = 0;
    for( auto w : rec.warriors )
    {
        int wns = w->GetMaxSoldierNumber() - w->GetSoldierNumber(); //  wns = warrior need soldier
        if( rec.town->GetSoldierNumber() > 0 )
        {
            int cangive = (rec.town->GetSoldierNumber() > wns) ? wns : rec.town->GetSoldierNumber();
            w->IncreaseSoldierNumber( cangive );
            rec.town->IncreaseSoldierNumber( -1 * cangive );
            wns -= cangive;
        }
        needsoldier += wns;
    }
    return needsoldier;
}

bool UKingdomRoundAi::AgricultureDevTask( UTown* town, UWarrior* warrior )
{
    auto task = NewObject<UTownAgricultureDevelopTask>( this );
    return task->SetBaseTown( town ) && task->SetTargetWarrior( warrior );
}

bool UKingdomRoundAi::BusinessDevTask( UTown* town, UWarrior* warrior )
{
    auto task = NewObject<UTownBusinessDevelopTask>( this );
    return task->SetBaseTown( town ) && task->SetTargetWarrior( warrior );
}

bool UKingdomRoundAi::ConscriptTask( UTown* town, UWarrior* warrior )
{
    return false;
}

bool UKingdomRoundAi_Chapter1::TownRound( FTownStatistics& rec )
{
    int needsoldier = this->GiveSoldlier( rec );
    this->DevTown( rec );

    if( (rec.town->GetFood() > 5000) && (needsoldier > 0) )
    {
        while( (rec.warriors.Num() > 0) && (rec.town->GetSoldierNumber() < needsoldier)
            && this->ConscriptTask( rec.town, rec.warriors.Pop() ) );
    }
    int sumsoldier = 0;
    for( auto w : rec.warriors )
    {
        sumsoldier += w->GetSoldierNumber();
    }
    if( ( this->m_n_round > 30 ) && (rec.town->GetFood() > 3000) && (rec.warriors.Num() > 3) && ( sumsoldier > 2000 ) )
    {
        auto nearbyHosile = rec.town->GetHostileNeighbours();
        UTown* fightTarget = nearbyHosile.Num() ? nearbyHosile[ 0 ] : nullptr;
    }

    return true;
}

bool UKingdomRoundAi_Chapter2::TownRound( FTownStatistics& rec )
{
    int needsoldier = this->GiveSoldlier( rec );
    this->DevTown( rec );

    if( (rec.town->GetFood() > 5000) && (needsoldier > 0) )
    {
        while( (rec.warriors.Num() > 0) && (rec.town->GetSoldierNumber() < needsoldier)
            && this->ConscriptTask( rec.town, rec.warriors.Pop() ) );
    }
    int sumsoldier = 0;
    for( auto w : rec.warriors )
    {
        sumsoldier += w->GetSoldierNumber();
    }
    if( (this->m_n_round > 20) && (rec.town->GetFood() > 3000) && (rec.warriors.Num() > 3) && (sumsoldier > 2000) )
    {
        auto nearbyHosile = rec.town->GetHostileNeighbours();
        UTown* fightTarget = nearbyHosile.Num() ? nearbyHosile[ 0 ] : nullptr;
    }

    return true;
}

bool UKingdomRoundAi_Chapter3::TownRound( FTownStatistics& rec )
{
    int needsoldier = this->GiveSoldlier( rec );
    this->DevTown( rec );

    if( (rec.town->GetFood() > 5000) && (needsoldier > 0) )
    {
        while( (rec.warriors.Num() > 0) && (rec.town->GetSoldierNumber() < needsoldier)
            && this->ConscriptTask( rec.town, rec.warriors.Pop() ) );
    }
    int sumsoldier = 0;
    for( auto w : rec.warriors )
    {
        sumsoldier += w->GetSoldierNumber();
    }
    if( (this->m_n_round > 10) && (rec.town->GetFood() > 3000) && (rec.warriors.Num() > 3) && (sumsoldier > 2000) )
    {
        auto nearbyHosile = rec.town->GetHostileNeighbours();
        UTown* fightTarget = nearbyHosile.Num() ? nearbyHosile[ 0 ] : nullptr;
    }

    return true;
}

bool UKingdomRoundAi_Chapter4::TownRound( FTownStatistics& rec )
{
    int needsoldier = this->GiveSoldlier( rec );
    this->DevTown( rec );

    if( (rec.town->GetFood() > 5000) && (needsoldier > 0) )
    {
        while( (rec.warriors.Num() > 0) && (rec.town->GetSoldierNumber() < needsoldier)
            && this->ConscriptTask( rec.town, rec.warriors.Pop() ) );
    }
    int sumsoldier = 0;
    for( auto w : rec.warriors )
    {
        sumsoldier += w->GetSoldierNumber();
    }
    if( (this->m_n_round > 5) && (rec.town->GetFood() > 3000) && (rec.warriors.Num() > 3) && (sumsoldier > 2000) )
    {
        auto nearbyHosile = rec.town->GetHostileNeighbours();
        UTown* fightTarget = nearbyHosile.Num() ? nearbyHosile[ 0 ] : nullptr;
    }

    return true;
}
