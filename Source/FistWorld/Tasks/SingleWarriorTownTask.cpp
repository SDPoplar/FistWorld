// Copyright 2019

#include "SingleWarriorTownTask.h"

USingleWarriorTownTask::USingleWarriorTownTask( const FObjectInitializer& ObjectInitializer )
    : UTownTask( ObjectInitializer ), m_o_warrior( nullptr )
{}

bool USingleWarriorTownTask::Excute()
{
    return this->m_o_warrior && UTownTask::Excute();
}

bool USingleWarriorTownTask::SetTargetWarrior( UWarrior* warrior )
{
    this->m_o_warrior = warrior;
    return !!warrior;
}
