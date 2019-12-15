// Copyright 2019

#include "TownExecuteWarriorTask.h"
#include "Huds/WorldMapHud.h"
#include "Story/Town.h"
#include "Story/Warrior.h"
#include "Static/Lang/WorldMessage.h"

UTownExecuteWarriorTask::UTownExecuteWarriorTask( const FObjectInitializer& ObjectInitializer )
    : UPrisonTownTask( ObjectInitializer )
{
    m_n_taskCost = 0;
}

bool UTownExecuteWarriorTask::Excute()
{
    if( !this->m_o_target_warrior || !USingleWarriorTownTask::Excute() )
    {
        this->MarkAsCanceled();
        return false;
    }
    this->m_o_town->IncreaseMoney( -1 * this->GetTaskCost( ) );
    this->m_o_target_warrior->SetStatus( EWarriorStatus::DEAD );
    this->m_o_warrior->SetStatus( EWarriorStatus::WORKING );
    this->m_b_create_by_ai || this->ShowNotice( FText::FormatOrdered<FText>( txtExecuteWarriorResult,
            FText::FromString( this->m_o_target_warrior->GetWarriorName() ) ) );
    this->MarkAsFinished();
    return true;
}