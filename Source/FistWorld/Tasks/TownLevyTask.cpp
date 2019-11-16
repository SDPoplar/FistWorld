// Copyright 2019

#include "TownLevyTask.h"
#include "Story/Warrior.h"
#include "Story/Town.h"
#include "Story/Kingdom.h"
#include "Controllers/WorldMapController.h"
#include "Huds/WorldMapHud.h"
#include "FistWorldInstance.h"

bool UTownLevyTask::SetTargetWarrior( UWarrior* warrior )
{
    if( !UTownTransportTask::SetTargetWarrior( warrior ) )
    {
        return false;
    }
    auto pc = AWorldMapController::GetInstance( this );
    auto hud = pc ? pc->GetWorldMapHud() : nullptr;
    return hud && hud->PopupTransportVolumeSetter( this->m_o_town->GetFood(), this->m_o_town->GetMoney() );
}

bool UTownLevyTask::Excute()
{
    auto gi = UFistWorldInstance::GetInstance( this );
    auto kingdom = gi ? gi->GetMyKingdom() : nullptr;
    if( !kingdom )
    {
        return false;
    }
    this->m_o_town->IncreaseFood( -1 * this->GetFood() );
    this->m_o_town->IncreaseMoney( -1 * this->GetMoney() );
    kingdom->IncreaseFood( this->GetFood() );
    kingdom->IncreaseMoney( this->GetMoney() );
    this->m_o_warrior->SetStatus( EWarriorStatus::WORKING );
    this->RemoveFromRoot();
    return true;
}
