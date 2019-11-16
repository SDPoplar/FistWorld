// Fill out your copyright notice in the Description page of Project Settings.


#include "TownTask.h"
#include "Story/Town.h"
#include "Story/Warrior.h"

UTownTask::UTownTask( const FObjectInitializer& ObjectInitializer ) : UExcutableTask( ObjectInitializer ), m_o_town( nullptr )
{}

void UTownTask::SetBaseTown( UTown* town )
{
    this->m_o_town = town;
    this->m_e_step = ETaskStep::CHOOSING_TARGET_WARRIOR;
}

UTownTask::~UTownTask()
{}

bool UTownTask::SetTargetWarrior( UWarrior* warrior )
{
    this->m_o_warrior = warrior;
    return true;
}
