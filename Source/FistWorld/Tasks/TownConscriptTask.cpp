// Copyright 2019

#include "TownConscriptTask.h"
#include "Story/Warrior.h"
#include "Story/Town.h"
#include "Controllers/WorldMapController.h"
#include "Huds/WorldMapHud.h"

bool UTownConscriptTask::SetTargetWarrior( UWarrior* warrior )
{
    if( !UTownSoldierNumTask::SetTargetWarrior( warrior ) )
    {
        return false;
    }

    int max = ( warrior->GetStrong() + warrior->GetIntel() ) / 20 * 50;
    max = max ? max : 100;
    return this->m_o_hud->PopupSoldierNumSetter( max );
}

bool UTownConscriptTask::Excute()
{
    if( !this->m_o_town || !this->m_o_warrior || (this->m_n_soldier_num <= 0) )
    {
        return false;
    }
    this->m_o_town->IncreaseSoldierNumber( this->GetSoldierNumber() );
    this->m_o_warrior->SetStatus( EWarriorStatus::WORKING );
    this->MarkAsFinished();
    return true;
}
