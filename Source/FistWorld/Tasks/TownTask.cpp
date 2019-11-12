// Fill out your copyright notice in the Description page of Project Settings.


#include "TownTask.h"
#include "Story/Town.h"
#include "Story/Warrior.h"

UTownTask::UTownTask() : UExcutableTask(), m_o_town( nullptr )
{}

UTownTask::UTownTask( UTown* town )
{
    this->m_o_town = town;
    this->m_e_step = ETaskStep::CHOOSING_TARGET_WARRIOR;
}

UTownTask::~UTownTask()
{}

void UTownTask::SetTargetWarrior( UWarrior* warrior )
{
    this->m_o_warrior = warrior;
}

UTownBusinessDevelopTask::UTownBusinessDevelopTask( UTown* town ) : UTownTask( town )
{}

void UTownBusinessDevelopTask::SetTargetWarrior( UWarrior* warrior )
{
    UTownTask::SetTargetWarrior( warrior );
    this->Excute();
}

bool UTownBusinessDevelopTask::Excute()
{
    return true;
}
