// Copyright 2019


#include "TownInduceCapitulateTask.h"
#include "Huds/WorldMapHud.h"
#include "Story/Town.h"
#include "Story/Warrior.h"
#include "Kismet/GameplayStatics.h"

UTownInduceCapitulateTask::UTownInduceCapitulateTask( const FObjectInitializer& ObjectInitializer ) : USingleWarriorTownTask( ObjectInitializer ), m_o_enermy_warrior( nullptr )
{}

bool UTownInduceCapitulateTask::SetTargetWarrior( UWarrior* warrior )
{
    return USingleWarriorTownTask::SetTargetWarrior( warrior ) && this->Excute( );
}



bool UTownInduceCapitulateTask::SetEnermyWarrior( UWarrior* warrior )
{
    this->m_o_enermy_warrior = warrior;
    return !!warrior;
}

void UTownInduceCapitulateTask::DemandForSurrender( )
{
    int nChoice = DoWhatToEnermyWarrior( );

    if( nChoice == 1 )
    {
        ExecuteWarrior( );
        return;
    }
    else 
    {
        if( BeginInduceCapitulate( ) )
        {
            InduceCapitulateSuccess( );
        }
        else
        {

        }
    }
    
}

bool UTownInduceCapitulateTask::BeginInduceCapitulate( )
{
    //TODO:: decide success or not
    return true;
}

int UTownInduceCapitulateTask::DoWhatToEnermyWarrior( )
{
    //TODO: Do you want to execute the enermy warrior or induce him to capitulate
    //( 1 ) execute him   ( 2 ) induce him to capitulate

    return 1;
}

void UTownInduceCapitulateTask::ExecuteWarrior( )
{
    this->m_o_enermy_warrior->SetStatus( EWarriorStatus::DEAD );
}


void UTownInduceCapitulateTask::InduceCapitulateSuccess( )
{
    this->m_o_enermy_warrior->SetBelongKingdom( this->m_o_warrior->GetBelongKingdom( ) );
    this->m_o_enermy_warrior->SetStatus( EWarriorStatus::NORMAL );
}

void UTownInduceCapitulateTask::InduceCapitulateFaile( )
{
    //TODO:: some effects of this induce capitulate attempt
}

bool UTownInduceCapitulateTask::Excute( )
{

    if( !this->m_o_town || !this->m_o_warrior || !this->m_o_enermy_warrior )
    {
        return false;
    }

    DemandForSurrender( );

    return true;
}
