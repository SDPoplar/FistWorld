// Copyright 2019

#include "WorldSysMenuWidget.h"
#include "GameModes/WorldMapMode.h"
#include "Kismet/GameplayStatics.h"

//  TODO: move the follow 5 lines into other file
#include "FistWorldInstance.h"
#include "Controllers/WorldMapController.h"
#include "Huds/WorldMapHud.h"
#include "Story/Warrior.h"

bool UWorldSysMenuWidget::SaveCurrentGame()
{
    auto gi = UFistWorldInstance::GetInstance( this );
    auto save = gi ? UFistWorldSave::CreateEmptySaveInstance() : nullptr;
    if( !save )
    {
        return false;
    }
    save->chapter = gi->GetCurrentChapter();
    save->round = gi->GetCurrentRound();
    for( auto item : gi->GetKingdomList() )
    {
        save->kingdoms.Push( FSaveKingdom( *item ) );
    }
    for( auto item : gi->GetTownList() )
    {
        save->towns.Push( FSaveTown( *item ) );
    }
    for( auto item : gi->GetWarriorList() )
    {
        save->warriors.Push( FSaveWarrior( *item ) );
    }
    bool saveResult = save->SaveToSlot( 0 );
    auto pc = AWorldMapController::GetInstance( this );
    auto hud = pc ? pc->GetWorldMapHud() : nullptr;
    if( hud )
    {
        if( saveResult )
        {
            hud->PopupSuccess( FText::FromString( "Game saved successfully" ) );
        }
        else
        {
            hud->PopupFailed( FText::FromString( "Failed to save game" ) );
        }
    }
    return saveResult;
}

bool UWorldSysMenuWidget::NextRound()
{
    auto gm = Cast<AWorldMapMode>( UGameplayStatics::GetGameMode( this ) );
    this->Quit();
    return gm && gm->FinishRound();
}
