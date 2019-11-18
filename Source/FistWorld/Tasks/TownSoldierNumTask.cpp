// Copyright 2019

#include "TownSoldierNumTask.h"
#include "Story/Warrior.h"

bool UTownSoldierNumTask::SetTargetWarrior( UWarrior* warrior )
{
    if( !USingleWarriorTownTask::SetTargetWarrior( warrior ) )
    {
        return false;
    }
    this->m_e_step = ETaskStep::SETTING_SOLDIER_NUMBER;
    return true;
}

bool UTownSoldierNumTask::SetTaskSoldierNumber( int num )
{
    if( this->m_e_step != ETaskStep::SETTING_SOLDIER_NUMBER )
    {
        return false;
    }
    this->SetSoldierNumber( num );
    return this->Excute();
}
