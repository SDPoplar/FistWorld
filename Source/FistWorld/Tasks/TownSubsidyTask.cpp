// Copyright 2019

#include "TownSubsidyTask.h"
#include "Story/Kingdom.h"
#include "Story/Town.h"
#include "Story/Warrior.h"
#include "Controllers/WorldMapController.h"
#include "Huds/WorldMapHud.h"
#include "FistWorldInstance.h"

bool UTownSubsidyTask::SetTargetWarrior( UWarrior* warrior )
{
    if( !UTownTransportTask::SetTargetWarrior( warrior ) )
    {
        return false;
    }
    auto gi = UFistWorldInstance::GetInstance( this );
    auto kingdom = gi ? gi->GetMyKingdom() : nullptr;
    return kingdom && this->m_o_hud->PopupTransportVolumeSetter( kingdom->GetFood(), kingdom->GetMoney() );
}

bool UTownSubsidyTask::Excute()
{
    auto gi = UFistWorldInstance::GetInstance( this );
    auto kingdom = gi ? gi->GetMyKingdom() : nullptr;
    if( !kingdom )
    {
        return false;
    }
    kingdom->IncreaseFood( -1 * this->GetFood() );
    kingdom->IncreaseMoney( -1 * this->GetMoney() );
    this->m_o_town->IncreaseFood( this->GetFood() );
    this->m_o_town->IncreaseMoney( this->GetMoney() );
    this->m_o_warrior->SetStatus( EWarriorStatus::WORKING );
    this->MarkAsFinished();
    return true;
}
