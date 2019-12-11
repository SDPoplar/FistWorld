// Fill out your copyright notice in the Description page of Project Settings.

#include "TownTask.h"
#include "Level/TownActor.h"
#include "Story/Town.h"
#include "Story/Warrior.h"
#include "Controllers/WorldMapController.h"
#include "Huds/WorldMapHud.h"
#include "Static/Lang/WorldMessage.h"

UTownTask::UTownTask( const FObjectInitializer& ObjectInitializer ) : UExcutableTask( ObjectInitializer ),
    m_o_town( nullptr ), m_o_target_town( nullptr ), m_o_pc( nullptr ), m_b_hide_townwidget_after_create( false )
{
}

UTownTask::~UTownTask()
{}

void UTownTask::SetBaseTown( UTown* town )
{
    this->m_o_pc = AWorldMapController::GetInstance( this );
    this->m_o_town = town;
    this->m_e_step = ETaskStep::CHOOSING_TARGET_WARRIOR;
}

bool UTownTask::SetTargetTown( UTown* town )
{
    if( !this->m_o_town->CanArrive( town ) )
    {
        this->ShowError( txtCannotArrive );
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

int UTownTask::GetTaskCost( void ) const noexcept //Tobe tested!
{
    return this->m_n_taskCost;
}

void UTownTask::PopAlert( const char* sAlerMessage ) const noexcept //Tobe tested!
{
    this->m_o_hud->PopupAlert( FText::FromString( sAlerMessage ) );
}

void UTownTask::SetTaskCostRate( float nTaskCostRate ) noexcept //Tobe tested!
{
    this->m_n_taskCost *= nTaskCostRate;
}
