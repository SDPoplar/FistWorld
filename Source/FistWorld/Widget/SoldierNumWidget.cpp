// Copyright 2019

#include "SoldierNumWidget.h"
#include "Widget/IntegerSliderWidget.h"
#include "Controllers/WorldMapController.h"
#include "Tasks/TownSoldierNumTask.h"

bool USoldierNumWidget::SetTaskSoldierNum( const UIntegerSliderWidget* slider )
{
    auto pc = AWorldMapController::GetInstance( this );
    UTownSoldierNumTask* task = pc ? Cast<UTownSoldierNumTask>( pc->GetTask() ) : nullptr;
    if( !task )
    {
        return false;
    }
    bool result = task->SetTaskSoldierNumber( slider->GetValue() );
    if( result )
    {
        this->Quit();
    }
    return result;
}
