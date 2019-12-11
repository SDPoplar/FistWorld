// Copyright 2019


#include "TownExecuteTask.h"
#include "Huds/WorldMapHud.h"
#include "Story/Town.h"
#include "Story/Warrior.h"
#include "Kismet/GameplayStatics.h"

UTownExecuteTask::UTownExecuteTask( const FObjectInitializer& ObjectInitializer ) : USingleWarriorTownTask( ObjectInitializer ), m_arr_prisions( )
{}

bool UTownExecuteTask::SetTargetWarrior( UWarrior* warrior )
{
    return USingleWarriorTownTask::SetTargetWarrior( warrior ) && this->Excute( );
}



bool UTownExecuteTask::AppendPrision( UWarrior* warrior )
{
    this->m_arr_prisions.AddUnique( warrior );
    
    return m_arr_prisions.Num( ) > 0;
}


void UTownExecuteTask::ExecuteWarrior( )
{
    for( auto item : this->m_arr_prisions )
    {
        item->SetStatus( EWarriorStatus::DEAD );
    }
        
}

bool UTownExecuteTask::Excute( )
{
    //TODO: select prisions
}