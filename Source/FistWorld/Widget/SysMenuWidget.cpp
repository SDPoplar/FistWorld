// Fill out your copyright notice in the Description page of Project Settings.

#include "SysMenuWidget.h"

//  TODO: move the follow 4 lines into other file
#include "FistWorldInstance.h"
#include "Controllers/WorldMapController.h"
#include "Huds/WorldMapHud.h"
#include "Story/Warrior.h"

bool USysMenuWidget::SaveCurrentGame()
{
    return false;
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
        hud->PopupAlert( "New Round!" );
    }
    this->Quit();
    return true;
}
