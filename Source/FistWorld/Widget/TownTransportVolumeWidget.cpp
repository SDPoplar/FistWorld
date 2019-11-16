// Copyright 2019

#include "TownTransportVolumeWidget.h"
#include "Controllers/WorldMapController.h"
#include "Tasks/TownTransportTask.h"
#include "Widget/IntegerSliderWidget.h"

bool UTownTransportVolumeWidget::SetTaskTransportVolume( const UIntegerSliderWidget* foodSlider, const UIntegerSliderWidget* moneySlider )
{
    auto pc = AWorldMapController::GetInstance( this );
    auto task = pc ? Cast<UTownTransportTask>( pc->GetTask() ) : nullptr;
    if( !task || !task->SetTransportVolume( foodSlider->GetValue(), moneySlider->GetValue() ) )
    {
        return false;
    }
    this->Quit();
    return true;
}
