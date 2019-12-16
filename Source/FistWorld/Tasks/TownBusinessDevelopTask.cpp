// Fill out your copyright notice in the Description page of Project Settings.

#include "TownBusinessDevelopTask.h"
#include "Story/Town.h"
#include "Story/Warrior.h"

UTownBusinessDevelopTask::UTownBusinessDevelopTask() : USingleWarriorTownTask()
{
    m_n_taskCost = 200;
}

bool UTownBusinessDevelopTask::SetTargetWarrior( UWarrior* warrior )
{
    return USingleWarriorTownTask::SetTargetWarrior( warrior ) && this->Excute();
}

bool UTownBusinessDevelopTask::Excute()
{
    if( !this->m_o_town || !this->m_o_warrior || !USingleWarriorTownTask::Excute( ) )
    {
        this->MarkAsCanceled( );
        return false;
    }
    this->m_o_town->GetBusinessDevelopment().IncreaseCurrent( this->m_o_warrior->GetIntel() );
    this->m_o_warrior->SetStatus( EWarriorStatus::WORKING );
    this->MarkAsFinished();
    return true;
}