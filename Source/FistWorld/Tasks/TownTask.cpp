// Fill out your copyright notice in the Description page of Project Settings.

#include "TownTask.h"
#include "Level/TownActor.h"
#include "Story/Town.h"
#include "Story/Warrior.h"

UTownTask::UTownTask( const FObjectInitializer& ObjectInitializer ) : UExcutableTask( ObjectInitializer ),
    m_o_actor( nullptr ), m_o_town( nullptr )
{}

void UTownTask::SetBaseTown( ATownActor* town )
{
    this->m_o_actor = town;
    this->m_o_town = town->GetTown();
    this->m_e_step = ETaskStep::CHOOSING_TARGET_WARRIOR;
}

UTownTask::~UTownTask()
{}
