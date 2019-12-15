// Copyright 2019

#include "TownTransportTask.h"
#include "Story/Warrior.h"

UTownTransportTask::UTownTransportTask( )
{
    m_n_taskCost = 120;
}

bool UTownTransportTask::SetTargetWarrior( UWarrior* warrior )
{
    if( !USingleWarriorTownTask::SetTargetWarrior( warrior ) )
    {
        return false;
    }
    this->m_e_step = ETaskStep::SETTING_TRANSPORT_VOLUME;
    return true;
}

bool UTownTransportTask::SetTransportVolume( int food, int money )
{
    this->SetFood( food );
    this->SetMoney( money );
    return this->Excute();
}
