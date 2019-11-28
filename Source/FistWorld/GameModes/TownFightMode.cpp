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

ATownFightMode::ATownFightMode() : m_o_current_fight( nullptr )
{
    PlayerControllerClass = AFightMapController::StaticClass();
    HUDClass = AFightMapHud::StaticClass();
    DefaultPawnClass = AFightMapViewer::StaticClass();
}

ATownFightMode* ATownFightMode::Get( UObject* getter )
{
    return Cast<ATownFightMode>( UGameplayStatics::GetGameMode( getter ) );
}

void ATownFightMode::LoadFirstFight( void )
{
    if( this->m_o_current_fight && this->m_o_current_fight->IsValidLowLevelFast() )
    {
        this->m_o_current_fight->RemoveFromRoot();
    }
    auto gi = UFistWorldInstance::GetInstance( this );
    if( !gi )
    {
        return;
    }
    if( !gi->HasFight() )
    {
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
        this->AttackerWin();
        return true;
    }
    UWorld* world = this->GetWorld();
    world->SpawnActor<AFightReporter>();
    auto level = world ? Cast<AFightLevelScript>( world->GetLevelScriptActor() ) : nullptr;
    if( !level )
    {
        return false;
    }
    //  spawn fight reporter
    AActor* attackSP = level->GetAttackStartPoint(), *defenceSP = level->GetDefenceStartPoint();
    for( auto item : this->m_o_current_fight->GetAttackerWarriors() )
    {
        auto fighter = AFightActor::SpawnWarrior( item, world );
        // set actor location
        fighter->SetActorLocation( attackSP->GetTargetLocation() );
    }
    for( auto item : this->AiChooseDefencer( this->m_o_current_fight->GetTargetTown(), 9 ) )
    {
        auto fighter = AFightActor::SpawnWarrior( item, world );
        fighter->SetActorLocation( defenceSP->GetTargetLocation() );
    }
    auto player = AFightMapViewer::Get<AFightMapViewer>( this );
    if( player )
    {
        player->PointTo( this->m_o_current_fight->IsPlayerAttack() ? attackSP : defenceSP );
    }
    return false;
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
    int attackerKingdomId = this->m_o_current_fight->GetAttackerKingdom()->GetKingdomId();
    this->m_o_current_fight->GetTargetTown()->SetOwnerKingdom( attackerKingdomId );
    this->LoadFirstFight();
}

void ATownFightMode::DefencerWin()
{
    this->LoadFirstFight();
}
