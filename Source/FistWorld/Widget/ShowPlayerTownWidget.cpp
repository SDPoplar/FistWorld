// Fill out your copyright notice in the Description page of Project Settings.

#include "ShowPlayerTownWidget.h"
#include "Tasks/TownTask.h"
#include "Kismet/GameplayStatics.h"
#include "Controllers/CommonMapController.h"
#include "Huds/WorldMapHud.h"
#include "Widget/SingleWarriorSelectWidget.h"
#include "Story/Town.h"

bool UShowPlayerTownWidget::CreateBusinessDevelopTask()
{
    if( !this->m_town )
    {
        return false;
    }
    auto pc = Cast<ACommonMapController>( UGameplayStatics::GetPlayerController( this, 0 ) );
    UTownBusinessDevelopTask* task = pc ? new UTownBusinessDevelopTask( this->m_town ) : nullptr;
    if( !task )
    {
        return false;
    }
    if( !pc->OverrideTask( task ) )
    {
        return false;
    }
    auto hud = Cast<AWorldMapHud>( pc->GetHUD() );
    if( !hud )
    {
        return false;
    }
    auto widget = hud->PopupSingleWarriorSelector();
    if( !widget )
    {
        return false;
    }
    widget->LoadListByTown( this->m_town->GetTownId(), false );
    return true;
}
