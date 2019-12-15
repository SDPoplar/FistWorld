// Fill out your copyright notice in the Description page of Project Settings.

#include "TownAgricultureDevelopTask.h"
#include "Story/Town.h"
#include "Story/Warrior.h"

UTownAgricultureDevelopTask::UTownAgricultureDevelopTask() : USingleWarriorTownTask()
{
    m_n_taskCost = 100;
}

bool UTownAgricultureDevelopTask::SetTargetWarrior( UWarrior* warrior )
{
    return USingleWarriorTownTask::SetTargetWarrior( warrior ) && this->Excute();
}

bool UTownAgricultureDevelopTask::Excute()
{
    if( !this->m_o_town || !this->m_o_warrior )
    {
        return false;
    }
    this->m_o_town->IncreaseMoney( -1 * this->GetTaskCost( ) );
    this->m_o_town->GetAgricultureDevelopment().IncreaseCurrent( this->m_o_warrior->GetStrong() );
    this->m_o_warrior->SetStatus( EWarriorStatus::WORKING );
    this->MarkAsFinished();
    return true;
}

