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
    return NewObject<UKingdomRoundAi_Chapter1>( gm )->SetCurrentRound( round );
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
    return this->m_n_round && this->m_o_kingdom && this->m_arr_towns.Num();
}

bool UKingdomRoundAi::DoRound()
{
    bool ret = this->Round();
    this->RemoveFromRoot();
    return ret;
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

bool UKingdomRoundAi_Chapter1::Round()
{
    if( !UKingdomRoundAi::Round() )
    {
        return false;
    }
    for( auto rec : this->m_arr_towns )
    {
        int needsoldier = 0;
        for( auto w : rec.warriors )
        {
            int wns = w->GetMaxSoldierNumber() - w->GetSoldierNumber(); //  wns = warrior need soldier
            if( rec.town->GetSoldierNumber() > 0 )
            {
                int cangive = ( rec.town->GetSoldierNumber() > wns ) ? wns : rec.town->GetSoldierNumber();
                w->IncreaseSoldierNumber( cangive );
                rec.town->IncreaseSoldierNumber( -1 * cangive );
                wns -= cangive;
            }
            needsoldier += wns;
        }

        while( (rec.warriors.Num() > 0) && (rec.town->GetAgricultureDevelopment().GetPercent() < 0.8)
            && this->AgricultureDevTask( rec.town, rec.warriors.Pop() ) );
        while( (rec.warriors.Num() > 0) && (rec.town->GetBusinessDevelopment().GetPercent() < 0.8)
            && this->BusinessDevTask( rec.town, rec.warriors.Pop() ) );
        while( (rec.warriors.Num() > 0) && !rec.town->GetAgricultureDevelopment().IsFull()
            && this->AgricultureDevTask( rec.town, rec.warriors.Pop() ) );
        while( (rec.warriors.Num() > 0) && !rec.town->GetBusinessDevelopment().IsFull()
            && this->BusinessDevTask( rec.town, rec.warriors.Pop() ) );

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
        if( (rec.town->GetFood() > 3000) && (rec.warriors.Num() > 3) && (sumsoldier > 2000)
            && (false /* has hostil town nearby */) )
        {
            //  make fight
        }
    }

    return true;
}
