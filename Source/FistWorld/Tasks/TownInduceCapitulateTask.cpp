// Copyright 2019


#include "TownInduceCapitulateTask.h"
#include "Huds/WorldMapHud.h"
#include "Story/Town.h"
#include "Story/Warrior.h"
#include "RandomMaker.h"
#include "Static/Lang/WorldMessage.h"

UTownInduceCapitulateTask::UTownInduceCapitulateTask( const FObjectInitializer& ObjectInitializer )
    : UPrisonTownTask( ObjectInitializer )
{
    this->m_n_taskCost = 50;
}

bool UTownInduceCapitulateTask::Excute()
{
    if( !this->m_o_target_warrior || !USingleWarriorTownTask::Excute() )
    {
        this->MarkAsCanceled();
        return false;
    }
    
    bool success = RandomMaker::WillHappen( this->m_o_warrior->GetIntel() - this->m_o_target_warrior->GetIntel() + 20 );
    if( success )
    {
        this->m_o_target_warrior->SetBelongKingdom( this->m_o_town->GetKingdomId() );
        this->m_o_target_warrior->SetStatus( EWarriorStatus::NORMAL );
        this->m_o_warrior->SetWarriorExp( this->m_o_warrior->GetWarriorExp() + 20 );
        this->m_b_create_by_ai || this->ShowNotice( FText::FormatOrdered<FText>( txtInduceCapitulateSuccess,
            FText::FromString( m_o_target_warrior->GetWarriorName() )  ) );
    }
    else
    {
        this->m_b_create_by_ai || this->ShowNotice( FText::FormatOrdered<FText>( txtInduceCapitulateFailed,
            FText::FromString( m_o_target_warrior->GetWarriorName() ) ) );
    }
    this->m_o_warrior->SetStatus( EWarriorStatus::WORKING );
    this->MarkAsFinished();
    return true;
}
