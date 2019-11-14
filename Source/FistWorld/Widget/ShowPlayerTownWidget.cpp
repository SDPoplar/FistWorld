// Fill out your copyright notice in the Description page of Project Settings.

#include "ShowPlayerTownWidget.h"
#include "Tasks/TownTask.h"
#include "Tasks/TownBusinessDevelopTask.h"
#include "Tasks/TownAgricultureDevelopTask.h"
#include "Kismet/GameplayStatics.h"
#include "Controllers/CommonMapController.h"
#include "Huds/WorldMapHud.h"
#include "Widget/SingleWarriorSelectWidget.h"
#include "Story/Town.h"

bool UShowPlayerTownWidget::CreateBusinessDevelopTask()
{
    return this->CreateTownTask( []( void )-> UTownTask* { return NewObject<UTownBusinessDevelopTask>(); } );
}

bool UShowPlayerTownWidget::CreateAgricultureDevelopTask()
{
    return this->CreateTownTask( []( void )->UTownTask* { return NewObject<UTownAgricultureDevelopTask>(); } );
}

bool UShowPlayerTownWidget::CreateTownTask( UTownTask*( taskmaker )( void ) )
{
    if( !this->m_town )
    {
        return false;
    }
    auto pc = Cast<ACommonMapController>( UGameplayStatics::GetPlayerController( this, 0 ) );
    UTownTask* task = pc ? taskmaker() : nullptr;
    if( !task )
    {
        return false;
    }
    task->SetBaseTown( this->m_town );
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
