// Fill out your copyright notice in the Description page of Project Settings.

#include "ShowPlayerTownWidget.h"
#include "Tasks/TownTask.h"
#include "Tasks/TownBusinessDevelopTask.h"
#include "Tasks/TownAgricultureDevelopTask.h"
#include "Tasks/TownSearchTask.h"
#include "Tasks/TownLevyTask.h"
#include "Tasks/TownSubsidyTask.h"
#include "Tasks/TownConscriptTask.h"
#include "Tasks/TownAssignSoldierTask.h"
#include "Tasks/TownExpenditionTask.h"
#include "Tasks/TownInduceCapitulateTask.h"
#include "Tasks/TownExecuteWarriorTask.h"
#include "Controllers/WorldMapController.h"
#include "Huds/WorldMapHud.h"
#include "Widget/SingleWarriorSelectWidget.h"
#include "Widget/MultiWarriorSelectWidget.h"
#include "FistWorldInstance.h"
#include "Story/Kingdom.h"
#include "Story/Town.h"

bool UShowPlayerTownWidget::CreateBusinessDevelopTask()
{
    return this->CreateSingleWarriorTask( []( UObject* outer )-> UTownTask* { return NewObject<UTownBusinessDevelopTask>( outer ); } );
}

bool UShowPlayerTownWidget::CreateAgricultureDevelopTask()
{
    return this->CreateSingleWarriorTask( []( UObject* outer )->UTownTask* { return NewObject<UTownAgricultureDevelopTask>( outer ); } );
}

bool UShowPlayerTownWidget::CreateTownSearchTask()
{
    return this->CreateSingleWarriorTask( []( UObject* outer )->UTownTask* { return NewObject<UTownSearchTask>( outer ); } );
}

bool UShowPlayerTownWidget::CreateTownLevyTask()
{
    return this->CreateSingleWarriorTask( []( UObject* outer )->UTownTask* { return NewObject<UTownLevyTask>( outer ); } );
}

bool UShowPlayerTownWidget::CreateTownSubsidyTask()
{
    return this->CreateSingleWarriorTask( []( UObject* outer )->UTownTask* { return NewObject<UTownSubsidyTask>( outer ); } );
}

bool UShowPlayerTownWidget::CreateTownConscriptTask()
{
    return this->CreateSingleWarriorTask( []( UObject* outer )->UTownTask* { return NewObject<UTownConscriptTask>( outer ); } );
}

bool UShowPlayerTownWidget::CreateAssignSoldierTask()
{
    return this->CreateSingleWarriorTask( []( UObject* outer )->UTownTask* { return NewObject<UTownAssignSoldierTask>( outer ); } );
}

bool UShowPlayerTownWidget::CreateExpenditionTask()
{
    return this->CreateMultiWarriorTask( []( UObject* outer )->UTownTask* { return NewObject<UTownExpenditionTask>( outer ); } );
}

bool UShowPlayerTownWidget::CreateInduceCapitulateTask()
{
    return this->CreateSingleWarriorTask( []( UObject* outer )->UTownTask* { return NewObject<UTownInduceCapitulateTask>( outer ); } );
}

bool UShowPlayerTownWidget::CreateExecuteWarriorTask()
{
    return this->CreateSingleWarriorTask( []( UObject* outer )->UTownTask* { return NewObject<UTownExecuteWarriorTask>( outer ); } );
}

bool UShowPlayerTownWidget::CreateTownTask( UTownTask*( taskmaker )( UObject* ), AWorldMapController*& pc )
{
    if( !this->m_town )
    {
        return false;
    }
    pc = pc ? pc : AWorldMapController::GetInstance( this );
    UTownTask* task = pc ? taskmaker( this ) : nullptr;
    if( !task )
    {
        return false;
    }
    task->MarkAsPlayerCreate();
    return task->SetBaseTown( this->m_town ) && task->Inited() && pc->OverrideTask( task );
}

bool UShowPlayerTownWidget::CreateSingleWarriorTask( UTownTask*( taskMaker )( UObject* ) )
{
    AWorldMapController* pc = nullptr;
    if( !this->CreateTownTask( taskMaker, pc ) )
    {
        return false;
    }

    auto hud = pc->GetWorldMapHud();
    if( !hud )
    {
        return false;
    }
    auto widget = hud->PopupSingleWarriorSelector();
    if( !widget )
    {
        return false;
    }
    widget->LoadListByTown( this->m_town->GetTownId(), true, false );
    auto task = Cast<UTownTask>( pc->GetTask() );
    if( task && task->CloseTownWidgetAfterCreate() )
    {
        this->Quit();
    }
    return true;
}

bool UShowPlayerTownWidget::CanSubsidy() const noexcept
{
    auto gi = UFistWorldInstance::GetInstance( this );
    UKingdom* kingdom = gi ? gi->GetMyKingdom() : nullptr;
    return kingdom && ( (kingdom->GetMoney() > 0) || (kingdom->GetFood() > 0) );
}

bool UShowPlayerTownWidget::CreateMultiWarriorTask( UTownTask* (taskMaker)(UObject*) )
{
    AWorldMapController* pc = nullptr;
    if( !this->CreateTownTask( taskMaker, pc ) )
    {
        return false;
    }
    auto hud = pc->GetWorldMapHud();
    if( !hud )
    {
        return false;
    }
    auto widget = hud->PopupMultiWarriorSelector();
    if( !widget )
    {
        return false;
    }
    widget->LoadListByTown( this->m_town->GetTownId(), true, false );
    auto task = Cast<UTownTask>( pc->GetTask() );
    if( task && task->CloseTownWidgetAfterCreate() )
    {
        this->Quit();
    }
    return true;
}
