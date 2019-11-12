// Fill out your copyright notice in the Description page of Project Settings.

#include "ShowPlayerTownWidget.h"
#include "Tasks/TownTask.h"
#include "Kismet/GameplayStatics.h"
#include "Controllers/CommonMapController.h"

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
    return pc->OverrideTask( task );
}
