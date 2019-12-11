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



bool UTownInduceCapitulateTask::SetPrision( UWarrior* warrior )
{
    this->m_o_enermy_warrior = warrior;
    return !!warrior;
}

void UTownInduceCapitulateTask::DemandPrisionSurrender( )
{
    
        
    if( BeginInduceCapitulate( ) )
    {
        InduceCapitulateSuccess( );
    }
    else
    {
        InduceCapitulateFail( );
    }
    
}

bool UTownInduceCapitulateTask::BeginInduceCapitulate( )
{
    //TODO:: decide success or not
    return true;
}

void UTownInduceCapitulateTask::InduceCapitulateSuccess( )
{
    this->m_o_enermy_warrior->SetBelongKingdom( this->m_o_warrior->GetBelongKingdom( ) );
    this->m_o_enermy_warrior->SetStatus( EWarriorStatus::NORMAL );
}

void UTownInduceCapitulateTask::InduceCapitulateFail( )
{
    //TODO:: some effects of this induce capitulate attempt
}

bool UTownInduceCapitulateTask::Excute( )
{

    if( !this->m_o_town || !this->m_o_warrior || !this->m_o_enermy_warrior )
    {
        return false;
    }

    DemandPrisionSurrender( );

    return true;
}
