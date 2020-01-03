// Copyright 2019

#include "TownTransportTask.h"
#include "Story/Town.h"

#include "FistWorldInstance.h"
#include "Controllers/WorldMapController.h"
#include "Huds/WorldMapHud.h"
#include "Static/Lang/WorldMessage.h"
#include "RandomMaker.h"

UTownTransportTask::UTownTransportTask( const FObjectInitializer& ObjectInitializer )
    : USingleWarriorTownTask( ObjectInitializer ), HasMoneyAndFood()
{
    this->m_n_taskCost = 120;
    this->m_b_hide_townwidget_after_create = true;
    //  this->m_o_target_arrive_mode = TownArriveMode::RecursionFriendly;
    this->m_o_target_arrive_mode = TownArriveMode::DirectFriendly;
}

bool UTownTransportTask::SetTargetWarrior( UWarrior* warrior )
{
    if( !USingleWarriorTownTask::SetTargetWarrior( warrior ) )
    {
        return false;
    }
    this->m_e_step = ETaskStep::SETTING_TRANSPORT_VOLUME;
    auto hud = this->GetMapHud();
    return hud&& hud->PopupTransportVolumeSetter( this->m_o_town->GetFood(), this->m_o_town->GetMoney() );
}

bool UTownTransportTask::SetTransportVolume( int food, int money )
{
    this->SetFood( food );
    this->SetMoney( money );
    this->m_e_step = ETaskStep::CHOOSING_TARGET_TOWN;
    return true;
}

bool UTownTransportTask::SetTargetTown( UTown* town )
{
    return UTownTask::SetTargetTown( town ) && this->Excute();
}

bool UTownTransportTask::Excute()
{
    auto gi = UFistWorldInstance::GetInstance( this );
    auto kingdom = gi ? gi->GetMyKingdom() : nullptr;
    if( !kingdom || !USingleWarriorTownTask::Excute() )
    {
        MarkAsCanceled();
        return false;
    }

    this->m_o_warrior->SetStatus( EWarriorStatus::WORKING );
    bool success = RandomMaker::WillHappen( 90 );

    this->m_o_town->IncreaseMoney( -1 * m_n_money );
    this->m_o_town->IncreaseFood( -1 * m_n_food );
    if( success )
    {
        this->m_o_target_town->IncreaseMoney( m_n_money );
        this->m_o_target_town->IncreaseFood( m_n_food );
    }

    this->ShowNotice( success ? txtTransportSuccess : txtTransportFailed );

    MarkAsFinished();

    return true;
}
