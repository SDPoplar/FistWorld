// Fill out your copyright notice in the Description page of Project Settings.

#include "TownTask.h"
#include "Level/TownActor.h"
#include "Story/Warrior.h"
#include "Controllers/WorldMapController.h"
#include "Huds/WorldMapHud.h"
#include "Static/Lang/WorldMessage.h"

UTownTask::UTownTask( const FObjectInitializer& ObjectInitializer ) : UExcutableTask( ObjectInitializer ),
    m_o_town( nullptr ), m_o_target_town( nullptr ), m_o_pc( nullptr ), m_b_hide_townwidget_after_create( false ),
    m_n_taskCost( 0 ), m_o_target_arrive_mode( TownArriveMode::Default() )
{}

UTownTask::~UTownTask()
{}

bool UTownTask::SetBaseTown( UTown* town )
{
    this->m_o_pc = AWorldMapController::GetInstance( this );
    this->m_o_town = town;
    this->m_e_step = ETaskStep::CHOOSING_TARGET_WARRIOR;
    if( town->GetMoney() > this->GetTaskCost() )
    {
        return true;
    }
    this->m_b_create_by_ai || this->ShowError( txtNotEnoughMoney );
    this->MarkAsCanceled();
    return false;
}

bool UTownTask::SetTargetTown( UTown* town )
{
    EArriveStatus status = this->m_o_town->GetArriveStatus( town, this->m_o_target_arrive_mode );
    if( status != EArriveStatus::CanArrive )
    {
        if( !this->m_b_create_by_ai )
        {
            switch( status )
            {

                case EArriveStatus::Self:
                this->ShowError( txtUseSelfAsTarget );
                break;
                
                case EArriveStatus::Friendly:
                this->ShowError( txtFriendlyTargetGiven );
                break;
                
                default:
                this->ShowError( txtCannotArrive );

            

            }
        }
        this->MarkAsCanceled();
        return false;
    }
    this->m_o_target_town = town;
    return true;
}

bool UTownTask::CloseTownWidgetAfterCreate( void ) const noexcept
{
    return this->m_b_hide_townwidget_after_create;
}

bool UTownTask::Inited() const noexcept
{
    return this->m_o_town && this->m_o_pc;
}

AWorldMapHud* UTownTask::GetMapHud() const
{
    return this->GetHud<AWorldMapHud>();
}

int UTownTask::GetTaskCost( void ) const noexcept
{
    return this->m_n_taskCost;
}

bool UTownTask::Excute()
{
    if( !this->m_o_town || (this->m_o_town->GetMoney() < this->GetTaskCost()) )
    {
        return false;
    }
    this->m_o_town->IncreaseMoney( -1 * this->GetTaskCost() );
    return true;
}

/*
 * no need now
void UTownTask::PopAlert( const char* sAlerMessage ) const noexcept //Tobe tested!
{
    this->m_o_hud->PopupAlert( FText::FromString( sAlerMessage ) );
}

void UTownTask::SetTaskCostRate( float nTaskCostRate ) noexcept //Tobe tested!
{
    this->m_n_taskCost *= nTaskCostRate;
}
*/
