// Copyright 2019

#include "TownFightMode.h"
#include "Controllers/FightMapController.h"
#include "Huds/FightMapHud.h"
#include "Level/WorldMapViewer.h"
#include "Level/Fight.h"
#include "Level/FightActor.h"
#include "Kismet/GameplayStatics.h"
#include "FistWorldInstance.h"

ATownFightMode::ATownFightMode() : m_o_current_fight( nullptr )
{
    PlayerControllerClass = AFightMapController::StaticClass();
    HUDClass = AFightMapHud::StaticClass();
    DefaultPawnClass = AWorldMapViewer::StaticClass();
}

ATownFightMode* ATownFightMode::Get( UObject* getter )
{
    return Cast<ATownFightMode>( UGameplayStatics::GetGameMode( getter ) );
}

void ATownFightMode::LoadFirstFight( void )
{
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
    this->LoadFight( gi->GetFightList()[ 0 ] );
}

bool ATownFightMode::LoadFight( UFight* fight )
{
    this->m_o_current_fight = fight;
    UWorld* world = this->GetWorld();
    for( auto item : fight->GetAttackerWarriors() )
    {
        AFightActor::SpawnWarrior( item, world );
        // set actor location
    }
    return false;
}
