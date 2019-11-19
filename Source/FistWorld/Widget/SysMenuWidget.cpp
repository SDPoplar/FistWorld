// Fill out your copyright notice in the Description page of Project Settings.

#include "SysMenuWidget.h"

//  TODO: move the follow 4 lines into other file
#include "FistWorldInstance.h"
#include "Controllers/WorldMapController.h"
#include "Huds/WorldMapHud.h"
#include "Story/Warrior.h"
#include "FistWorldSave.h"

bool USysMenuWidget::SaveCurrentGame()
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

bool USysMenuWidget::NextRound()
{
    auto gi = UFistWorldInstance::GetInstance( this );
    if( !gi )
    {
        return false;
    }
    for( auto warrior : gi->GetWarriorList() )
    {
        if( warrior->GetStatus() == EWarriorStatus::WORKING )
        {
            warrior->SetStatus( EWarriorStatus::NORMAL );
        }
    }
    auto pc = AWorldMapController::GetInstance( this );
    auto hud = pc ? pc->GetWorldMapHud() : nullptr;
    if( hud )
    {
        hud->PopupAlert( FText::FromString( "New Round!" ) );
    }
    this->Quit();
    return true;
}

void USysMenuWidget::ConfirmBack()
{
    auto pc = AWorldMapController::GetInstance( this );
    auto hud = pc ? pc->GetWorldMapHud() : nullptr;
    hud&& hud->PopupConfirmBackWidget();
}
