// Copyright 2019


#include "TownAssignSoldierTask.h"
#include "Story/Warrior.h"
#include "Story/Town.h"
#include "Controllers/WorldMapController.h"
#include "Huds/WorldMapHud.h"

bool UTownAssignSoldierTask::SetTargetWarrior( UWarrior* warrior )
{
    if( !UTownSoldierNumTask::SetTargetWarrior( warrior ) )
    {
        return false;
    }
    if( this->m_b_create_by_ai )
    {
        return true;
    }

    int canhave = warrior->GetMaxSoldierNumber();
    int townhave = this->m_o_town->GetSoldierNumber() + this->m_o_warrior->GetSoldierNumber();
    int max = ( canhave < townhave ) ? canhave : townhave;
    return this->GetMapHud()->PopupSoldierNumSetter( max, this->m_o_warrior->GetSoldierNumber() );
}

bool UTownAssignSoldierTask::Excute()
{
    if( !this->m_o_town || !this->m_o_warrior || (this->m_n_soldier_num < 0) )
    {
        return false;
    }
    int delta = this->GetSoldierNumber() - this->m_o_warrior->GetSoldierNumber();
    this->m_o_town->IncreaseSoldierNumber( -1 * delta );
    this->m_o_warrior->SetSoldierNumber( this->GetSoldierNumber() );
    this->MarkAsFinished();
    return true;
}

