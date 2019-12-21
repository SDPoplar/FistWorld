// Copyright 2019

#include "TownTransportTask.h"
#include "Story/Town.h"

#include "FistWorldInstance.h"
#include "Controllers/WorldMapController.h"
#include "Huds/WorldMapHud.h"
#include "Static/Lang/WorldMessage.h"

UTownTransportTask::UTownTransportTask( const FObjectInitializer& ObjectInitializer )
    : USingleWarriorTownTask( ObjectInitializer ), HasMoneyAndFood()
{
    m_n_taskCost = 120;
}

bool UTownTransportTask::SetTargetWarrior( UWarrior* warrior )
{
    if( !USingleWarriorTownTask::SetTargetWarrior( warrior ) )
    {
        return false;
    }
    this->m_e_step = ETaskStep::SETTING_TRANSPORT_VOLUME; 
    auto gi = UFistWorldInstance::GetInstance( this );
    auto kingdom = gi ? gi->GetMyKingdom( ) : nullptr;
    return kingdom && this->GetMapHud( )->PopupTransportVolumeSetter( kingdom->GetFood( ), kingdom->GetMoney( ) );
}

bool UTownTransportTask::SetTransportVolume( int food, int money )
{
    
    this->SetFood( food );
    this->SetMoney( money );
    return this->Excute();
}

bool UTownTransportTask::Excute( )
{
    if( !UTownTask::Excute( ) )
    {
        this->MarkAsCanceled( );
        return false;
    }

    if( this->m_o_town->GetKingdomId( ) != this->m_o_target_town->GetKingdomId( ) )
    {
        this->ShowNotice( FText::FromString( "You can't transport money and food to an enermy town!!!" ) );
        this->MarkAsCanceled( );
        return false;
    }

    this->m_o_warrior->SetStatus( EWarriorStatus::WORKING );

    this->m_o_town->IncreaseMoney( -1 * m_n_money );
    this->m_o_target_town->IncreaseMoney( m_n_money );
    this->m_o_town->IncreaseFood( -1 * m_n_food );
    this->m_o_target_town->IncreaseFood( m_n_food );

    this->ShowNotice( txtTrasportStart );

    MarkAsFinished( );

    return true;
}
