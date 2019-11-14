// Fill out your copyright notice in the Description page of Project Settings.

#include "TownAgricultureDevelopTask.h"
#include "Story/Town.h"
#include "Story/Warrior.h"

UTownAgricultureDevelopTask::UTownAgricultureDevelopTask() : UTownTask()
{}

bool UTownAgricultureDevelopTask::SetTargetWarrior( UWarrior* warrior )
{
    return UTownTask::SetTargetWarrior( warrior ) && this->Excute();
}

bool UTownAgricultureDevelopTask::Excute()
{
    this->m_o_town->GetAgricultureDevelopment().IncreaseCurrent( 50 );
    this->m_o_warrior->SetStatus( EWarriorStatus::WORKING );
    this->RemoveFromRoot();
    return true;
}

