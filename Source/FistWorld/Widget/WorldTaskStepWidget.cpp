// Copyright 2019

#include "WorldTaskStepWidget.h"
#include "Controllers/WorldMapController.h"

void UWorldTaskStepWidget::QuitAndCancelTask()
{
    auto pc = AWorldMapController::GetInstance( this );
    if( !pc )
    {
        UE_LOG( LogTemp, Error, TEXT( "Failed to get player controller" ) );
        return;
    }
    pc->CancelCreatingTask();
    this->Quit();
}
