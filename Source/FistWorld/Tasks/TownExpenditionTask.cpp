// Copyright 2019

#include "TownExpenditionTask.h"
#include "Story/Town.h"
#include "Level/Fight.h"
#include "FistWorldInstance.h"
#include "Controllers/WorldMapController.h"
#include "Huds/WorldMapHud.h"
#include "Static/Lang/WorldMessage.h"

UTownExpenditionTask::UTownExpenditionTask( const FObjectInitializer& ObjectInitliazer )
    : UMultiWarriorTownTask( ObjectInitliazer )
{
    this->m_b_hide_townwidget_after_create = true;
}

bool UTownExpenditionTask::WarriorSetted()
{
    if( !UMultiWarriorTownTask::WarriorSetted() )
    {
        return false;
    }
    this->m_e_step = ETaskStep::CHOOSING_TARGET_TOWN;
    return true;
}

bool UTownExpenditionTask::SetTargetTown( UTown* town )
{
    return UTownTask::SetTargetTown( town ) && this->Excute();
}

bool UTownExpenditionTask::Excute()
{
    auto gi = UFistWorldInstance::GetInstance( this );
    auto kingdom = gi ? gi->GetPlayerKingdom() : nullptr;
    auto fight = kingdom ? new UFight( kingdom, this->m_o_town, this->m_o_target_town ) : nullptr;
    if( !fight )
    {
        return false;
    }
    this->EachWarrior(
        []( UWarrior* warrior, void* f )->bool {
            if( warrior->GetStatus() != EWarriorStatus::NORMAL )
            {
                return false;
            }
            UFight* fight = (UFight*)f;
            fight->AppendAttackerWarrior( warrior );
            warrior->SetStatus( EWarriorStatus::WORKING );
            return true;
        }, (void*)fight );
    if( !fight->IsValid() )
    {
        this->ShowError( txtCreateFightFailed );
        this->MarkAsCanceled();
        return false;
    }
    gi->AppendFight( fight );
    this->MarkAsFinished();
    this->ShowNotice( txtFightCreated );
    return true;
}
