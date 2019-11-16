// Fill out your copyright notice in the Description page of Project Settings.

#include "ShowPlayerTownWidget.h"
#include "Tasks/TownTask.h"
#include "Tasks/TownBusinessDevelopTask.h"
#include "Tasks/TownAgricultureDevelopTask.h"
#include "Tasks/TownSearchTask.h"
#include "Tasks/TownLevyTask.h"
#include "Tasks/TownSubsidyTask.h"
#include "Tasks/TownConscriptTask.h"
#include "Kismet/GameplayStatics.h"
#include "Controllers/CommonMapController.h"
#include "Huds/WorldMapHud.h"
#include "Widget/SingleWarriorSelectWidget.h"
#include "Story/Town.h"

bool UShowPlayerTownWidget::CreateBusinessDevelopTask()
{
    return this->CreateTownTask( []( UObject* outer )-> UTownTask* { return NewObject<UTownBusinessDevelopTask>( outer ); } );
}

bool UShowPlayerTownWidget::CreateAgricultureDevelopTask()
{
    return this->CreateTownTask( []( UObject* outer )->UTownTask* { return NewObject<UTownAgricultureDevelopTask>( outer ); } );
}

bool UShowPlayerTownWidget::CreateTownSearchTask()
{
    return this->CreateTownTask( []( UObject* outer )->UTownTask* { return NewObject<UTownSearchTask>( outer ); } );
}

bool UShowPlayerTownWidget::CreateTownLevyTask()
{
    return this->CreateTownTask( []( UObject* outer )->UTownTask* { return NewObject<UTownLevyTask>( outer ); } );
}

bool UShowPlayerTownWidget::CreateTownSubsidyTask()
{
    return this->CreateTownTask( []( UObject* outer )->UTownTask* { return NewObject<UTownSubsidyTask>( outer ); } );
}

bool UShowPlayerTownWidget::CreateTownConscriptTask()
{
    return this->CreateTownTask( []( UObject* outer )->UTownTask* { return NewObject<UTownConscriptTask>( outer ); } );
}

bool UShowPlayerTownWidget::CreateTownTask( UTownTask*( taskmaker )( UObject* ) )
{
    if( !this->m_town )
    {
        return false;
    }
    auto pc = Cast<ACommonMapController>( UGameplayStatics::GetPlayerController( this, 0 ) );
    UTownTask* task = pc ? taskmaker( this ) : nullptr;
    if( !task )
    {
        return false;
    }
    task->SetBaseTown( this->m_town );
    //  TODO: check task cost
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
