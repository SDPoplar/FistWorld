// Copyright 2019

#include "TownLevyTask.h"
#include "Story/Warrior.h"
#include "Story/Town.h"
#include "Story/Kingdom.h"
#include "Controllers/WorldMapController.h"
#include "Huds/WorldMapHud.h"
#include "FistWorldInstance.h"

UTownLevyTask::UTownLevyTask( )
{
    m_n_taskCost = 20;
}

bool UTownLevyTask::SetTargetWarrior( UWarrior* warrior )
{
    return UTownTransportTask::SetTargetWarrior( warrior ) && ( this->m_b_create_by_ai
        || this->GetMapHud()->PopupTransportVolumeSetter( this->m_o_town->GetFood(), this->m_o_town->GetMoney() ) );
}

bool UTownLevyTask::Excute()
{
    auto gi = UFistWorldInstance::GetInstance( this );
    auto kingdom = gi ? gi->GetMyKingdom() : nullptr;
    if( !kingdom || !USingleWarriorTownTask::Excute() )
    {
        MarkAsCanceled( );
        return false;
    }
    
    this->m_o_town->IncreaseFood( -1 * this->GetFood() );
    this->m_o_town->IncreaseMoney( -1 * this->GetMoney() );
    kingdom->IncreaseFood( this->GetFood() );
    kingdom->IncreaseMoney( this->GetMoney() );
    this->m_o_warrior->SetStatus( EWarriorStatus::WORKING );
    this->MarkAsFinished();
    return true;
}
