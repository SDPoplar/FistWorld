// Copyright 2019

#include "PrisonTownTask.h"
#include "Story/Warrior.h"
#include "Story/Town.h"
#include "Huds/WorldMapHud.h"
#include "Widget/SingleWarriorSelectWidget.h"

UPrisonTownTask::UPrisonTownTask( const FObjectInitializer& ObjectInitializer )
    : USingleWarriorTownTask( ObjectInitializer ), m_o_target_warrior( nullptr )
{}

bool UPrisonTownTask::SetTargetWarrior( UWarrior* warrior )
{
    if( this->m_o_warrior )
    {
        this->m_o_target_warrior = warrior;
        UE_LOG( LogTemp, Display, TEXT( "Target warrior setted" ) );
        return this->Excute();
    }
    if( !USingleWarriorTownTask::SetTargetWarrior( warrior ) )
    {
        this->MarkAsCanceled();
        UE_LOG( LogTemp, Display, TEXT( "Failed to set base warrior" ) );
        return false;
    }
    if( this->m_b_create_by_ai )
    {
        return true;
    }
    auto hud = this->GetMapHud();
    if( !hud )
    {
        UE_LOG( LogTemp, Error, TEXT( "Failed to get hud" ) );
        this->MarkAsCanceled();
        return false;
    }
    hud->PopupSingleWarriorSelector()->LoadListByPrison( this->m_o_town->GetTownId() );
    UE_LOG( LogTemp, Display, TEXT( "Waiting player to choose prison warrior" ) );
    return true;
}
