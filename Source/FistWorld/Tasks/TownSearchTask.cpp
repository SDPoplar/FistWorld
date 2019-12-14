// Copyright 2019

#include "TownSearchTask.h"
#include "Huds/WorldMapHud.h"
#include "Story/Town.h"
#include "Story/Warrior.h"
#include "Kismet/GameplayStatics.h"

UTownSearchTask::UTownSearchTask( const FObjectInitializer& ObjectInitializer ) : USingleWarriorTownTask( ObjectInitializer )
{
    m_n_taskCost = 50;
}

bool UTownSearchTask::SetTargetWarrior( UWarrior* warrior )
{
    return USingleWarriorTownTask::SetTargetWarrior( warrior ) && this->Excute();
}

bool UTownSearchTask::Excute()
{
    if( !this->m_o_town || !this->m_o_warrior )
    {
        return false;
    }
    //  TODO: find something
    
    this->ShowNotice( FText::FromString( "100 money found" ) );
    this->m_o_town->IncreaseMoney( 100 );
    this->m_o_warrior->SetStatus( EWarriorStatus::WORKING );
    this->MarkAsFinished();
    return true;
}
