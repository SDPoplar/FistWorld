// Copyright 2019

#include "TownFightMode.h"
#include "Controllers/FightMapController.h"
#include "Huds/FightMapHud.h"
#include "Level/FightMapViewer.h"
#include "Level/Fight.h"
#include "Level/FightActor.h"
#include "Level/FightReporter.h"
#include "Level/FightLevelScript.h"
#include "Story/Town.h"
#include "Story/Warrior.h"
#include "Kismet/GameplayStatics.h"
#include "FistWorldInstance.h"
#include "Widget/FightResultWidget.h"
#include "RandomMaker.h"

ATownFightMode::ATownFightMode() : m_o_current_fight( nullptr )
{
    PlayerControllerClass = AFightMapController::StaticClass();
    HUDClass = AFightMapHud::StaticClass();
    DefaultPawnClass = AFightMapViewer::StaticClass();
}

/*
ATownFightMode::~ATownFightMode()
{
    if( this->m_o_current_fight && this->m_o_current_fight->IsValidLowLevelFast() )
    {
        this->m_o_current_fight->RemoveFromRoot();
        this->m_o_current_fight = nullptr;
    }
}
*/

ATownFightMode* ATownFightMode::Get( UObject* getter )
{
    return Cast<ATownFightMode>( UGameplayStatics::GetGameMode( getter ) );
}

void ATownFightMode::LoadFirstFight( void )
{
    if( this->m_o_current_fight && this->m_o_current_fight->IsValidLowLevelFast() )
    {
        this->m_o_current_fight->ReleaseReporter();
        this->m_o_current_fight->RemoveFromRoot();
    }
    auto gi = UFistWorldInstance::GetInstance( this );
    if( !gi )
    {
        return;
    }
    if( !gi->HasFight() )
    {
        //  TODO: Clear dead kingdom
        UGameplayStatics::OpenLevel( this, "LV_World" );
        return;
    }
    this->LoadFight( gi->GetFightList().Pop() );
}

bool ATownFightMode::LoadFight( UFight* fight )
{
    this->m_o_current_fight = NewObject<UFightIns>( this );
    this->m_o_current_fight->AddToRoot();
    *( this->m_o_current_fight ) = fight;
    this->m_o_current_fight->SetDefencer( this->AiChooseDefencer( fight->GetTargetTown(), 9 ) );
    delete fight;
    if( this->m_o_current_fight->GetDefencerWarriors().Num() == 0 )
    {
        UE_LOG( LogTemp, Display, TEXT( "No defencer, so attacker win" ) );
        this->AttackerWin();
        return true;
    }
    UWorld* world = this->GetWorld();
    auto reporter = world->SpawnActor<AFightReporter>();
    this->m_o_current_fight->BindReporter( reporter );
    auto level = world ? Cast<AFightLevelScript>( world->GetLevelScriptActor() ) : nullptr;
    if( !level )
    {
        return false;
    }
    //  spawn fight reporter
    level->ResetBothBirthPoint();
    for( auto item : this->m_o_current_fight->GetAttackerWarriors() )
    {
        auto fighter = AFightActor::SpawnWarrior( item, world );
        // set actor location
        fighter->SetActorLocation( level->GetAttackerNextBirthPoint() );
        reporter->AppendAttacker( fighter );
    }
    for( auto item : this->AiChooseDefencer( this->m_o_current_fight->GetTargetTown(), 9 ) )
    {
        auto fighter = AFightActor::SpawnWarrior( item, world );
        fighter->SetActorLocation( level->GetDefencerNextBirthPoint() );
        reporter->AppendDefencer( fighter );
    }
    auto player = AFightMapViewer::Get<AFightMapViewer>( this );
    if( player )
    {
        player->PointTo( this->m_o_current_fight->IsPlayerAttack()
            ? level->GetAttackStartPoint()
            : level->GetDefenceStartPoint() );
        player->SaveCameraOrigin();
    }
    
    auto pc = AFightMapController::Get( this );
    auto hud = pc ? pc->GetFightHud() : nullptr;
    return hud && hud->PopFightCountDown( 3, reporter );
}

TArray<UWarrior*> ATownFightMode::AiChooseDefencer( UTown* town, int max )
{
    TArray<UWarrior*> ret;
    auto gi = UFistWorldInstance::GetInstance( this );
    if( !gi )
    {
        return ret;
    }

    for( auto item : gi->GetWarriorList() )
    {
        if( item->GetInTown() != town->GetTownId() )
        {
            continue;
        }
        if( (item->GetStatus() != EWarriorStatus::NORMAL) && (item->GetStatus() != EWarriorStatus::WORKING) )
        {
            continue;
        }
        ret.Add( item );
    }
    /*
    ret.Sort(
        []( const UWarrior* a, const UWarrior* b )->const bool {
            return a->GetFightMark() < b->GetFightMark();
        } );
    if( ret.Num() > max )
    {
        ret.SetNum( max );
    }
        */

    return ret;
}

void ATownFightMode::AttackerWin()
{
    int originKingdomId = this->m_o_current_fight->GetTargetTown()->GetKingdomId();
    UTown* runawayTarget = this->m_o_current_fight->GetTargetTown()->GetFirstRunAwayTarget();
    int attackerKingdomId = this->m_o_current_fight->GetAttackerKingdom()->GetKingdomId();
    this->m_o_current_fight->GetTargetTown()->SetOwnerKingdom( attackerKingdomId );
    int thisTownId = this->m_o_current_fight->GetTargetTown()->GetTownId();
    auto gi = UFistWorldInstance::GetInstance( this );
    for( auto warrior : gi->GetWarriorList() )
    {
        if( (warrior->GetInTown() != thisTownId) || (warrior->GetBelongKingdom() != originKingdomId) )
        {
            continue;
        }
        warrior->SetStatus( EWarriorStatus::MISSING );
    }
    for( auto warrior : this->m_o_current_fight->GetDefencerWarriors() )
    {
        if( runawayTarget && RandomMaker::IntRange( 0, warrior->GetSoldierNumber() ? 4 : 2 ) )
        {
            UE_LOG( LogTemp, Display, TEXT( "%s has run away to %s" ), *( warrior->GetWarriorName() ), *( runawayTarget->GetTownName() ) );
            warrior->SetInTown( runawayTarget->GetTownId() );
            warrior->SetStatus( EWarriorStatus::NORMAL );
        }
        else
        {
            warrior->SetStatus( EWarriorStatus::PRISON );
        }
    }
    for( auto warrior : this->m_o_current_fight->GetAttackerWarriors() )
    {
        warrior->SetInTown( thisTownId );
    }
    this->LoadFirstFight();
}

void ATownFightMode::DefencerWin()
{
    for( auto warrior : this->m_o_current_fight->GetAttackerWarriors() )
    {
        if( RandomMaker::WillHappen( 60 ) )
        {
            continue;
        }
        warrior->SetInTown( this->m_o_current_fight->GetTargetTown()->GetTownId() );
        warrior->SetStatus( EWarriorStatus::PRISON );
    }
    this->LoadFirstFight();
}

void ATownFightMode::FightFinish( bool attackerWin, TArray<FText> attackerResult, TArray<FText> defencerResult )
{
    if( !this->m_o_current_fight || !this->m_o_current_fight->IsValidLowLevelFast() )
    {
        return;
    }
    auto pc = AFightMapController::Get( this );
    auto hud = pc ? pc->GetFightHud() : nullptr;
    auto widget = hud ? hud->GetFightResultWidget() : nullptr;
    if( !widget )
    {
        UE_LOG( LogTemp, Error, TEXT( "Failed to get fight result widget in gamemode" ) );
        return;
    }
    widget->Popup();
    widget->SetFightResult( this->m_o_current_fight->IsPlayerAttack(), attackerWin, attackerResult, defencerResult );
}
