// Fill out your copyright notice in the Description page of Project Settings.

#include "SingleWarriorSelectWidget.h"
#include "Controllers/WorldMapController.h"

void USingleWarriorSelectWidget::QuitAndCancelTask()
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
