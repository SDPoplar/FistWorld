// Copyright 2019


#include "TownWarriorDeploymentTask.h"
#include "Story/Town.h"

#include "FistWorldInstance.h"
#include "Controllers/WorldMapController.h"
#include "Huds/WorldMapHud.h"
#include "Static/Lang/WorldMessage.h"

UTownWarriorDeploymentTask::UTownWarriorDeploymentTask( const FObjectInitializer& ObjectInitializer )
   : UMultiWarriorTownTask( ObjectInitializer )
{
    this->m_b_hide_townwidget_after_create = true;
    this->m_n_taskCost = 150;
    this->m_o_target_arrive_mode = TownArriveMode::RecursionFriendly;
}

bool UTownWarriorDeploymentTask::WarriorSetted()
{
    if( !UMultiWarriorTownTask::WarriorSetted() )
    {
        return false;
    }
    this->m_e_step = ETaskStep::CHOOSING_TARGET_TOWN;
    return true;
}

bool UTownWarriorDeploymentTask::SetTargetTown( UTown* town )
{
    return UTownTask::SetTargetTown( town ) && this->Excute();
}

bool UTownWarriorDeploymentTask::Excute()
{
    if( !UTownTask::Excute() )
    {
        this->MarkAsCanceled();
        return false;
    } 

    for( auto warrior : this->m_arr_warriors )
    {
        warrior->SetInTown( m_o_target_town->GetTownId() );
        warrior->SetStatus( EWarriorStatus::WORKING );
    }
    
    this->MarkAsFinished();
    this->ShowNotice( FText::FormatOrdered<FText>( txtDeploymentSuccess,
        FText::FromString( this->m_o_target_town->GetTownName() ) ) );
    return true;
}
