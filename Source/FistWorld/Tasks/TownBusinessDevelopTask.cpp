// Fill out your copyright notice in the Description page of Project Settings.

#include "TownBusinessDevelopTask.h"
#include "Story/Town.h"
#include "Story/Warrior.h"

UTownBusinessDevelopTask::UTownBusinessDevelopTask() : UTownTask()
{}

bool UTownBusinessDevelopTask::SetTargetWarrior( UWarrior* warrior )
{
    return UTownTask::SetTargetWarrior( warrior ) && this->Excute();
}

bool UTownBusinessDevelopTask::Excute()
{
    this->m_o_town->GetBusinessDevelopment().IncreaseCurrent( 50 );
    this->m_o_warrior->SetStatus( EWarriorStatus::WORKING );
    this->RemoveFromRoot();
    return true;
}