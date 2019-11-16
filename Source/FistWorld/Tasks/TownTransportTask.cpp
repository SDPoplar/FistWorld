// Copyright 2019

#include "TownTransportTask.h"
#include "Story/Warrior.h"

bool UTownTransportTask::SetTargetWarrior( UWarrior* warrior )
{
    if( !UTownTask::SetTargetWarrior( warrior ) )
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
