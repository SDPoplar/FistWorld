// Fill out your copyright notice in the Description page of Project Settings.

#include "SingleWarriorSelectWidget.h"
#include "Controllers/WorldMapController.h"
#include "Story/Warrior.h"
#include "Tasks/ExcutableTask.h"

void USingleWarriorSelectWidget::WarriorSelected( UWarriorIns* warrior )
{
    if( !warrior || !warrior->IsValidLowLevelFast() )
    {
        return;
    }
    auto pc = AWorldMapController::GetInstance( this );
    if( !pc || !pc->HasTask() )
    {
        return;
    }

    if( pc->SetTaskSelectingWarrior( warrior ) && ( pc->GetTask()->GetStep() != ETaskStep::CHOOSING_TARGET_WARRIOR ) )
    {
        this->Quit();
    }
}
