// Fill out your copyright notice in the Description page of Project Settings.


#include "CommonMapController.h"
#include "Huds/CommonMapHud.h"
#include "Tasks/ExcutableTask.h"
#include "Level/CommonMapViewer.h"

ACommonMapController::ACommonMapController( const FObjectInitializer& ObjectInitializer )
    : AModeOverridableController( ObjectInitializer ), m_map_viewport_edge_lock( {
        std::make_pair( EViewportEdge::TOP, false ), std::make_pair( EViewportEdge::LEFT, false ),
        std::make_pair( EViewportEdge::RIGHT, false ), std::make_pair( EViewportEdge::BOTTOM, false )
    } )
{}

/*
ACommonMapController::~ACommonMapController()
{
    if( this->m_o_task && this->m_o_task->IsValidLowLevelFast() )
    {
        this->m_o_task->RemoveFromRoot();
        this->m_o_task = nullptr;
    }
}
*/

void ACommonMapController::BeginPlay()
{
    Super::BeginPlay();

    this->bEnableClickEvents = true;
    //  this->bEnableTouchOverEvents = true;
    this->bEnableMouseOverEvents = true;
    this->m_o_task = nullptr;
    //  this->CancelCreatingTask();
}

void ACommonMapController::SetupInputComponent()
{
    Super::SetupInputComponent();

    this->InputComponent->BindAction( "PressEscape", IE_Released, this, &ACommonMapController::CancelOrCallSysMenu );
}

void ACommonMapController::CancelOrCallSysMenu()
{
    if( this->CancelCreatingTask() )
    {
        return;
    }
    auto hud = Cast<ACommonMapHud>( this->GetHUD() );
    hud && (hud->CloseAllPopup() || hud->ShowSysMenu());
}

bool ACommonMapController::CancelCreatingTask()
{
    if( !this->HasTask() || !this->m_o_task->CanCancel() )
    {
        return false;
    }
    this->m_o_task->MarkAsCanceled();
    this->m_o_task = nullptr;
    return true;
}

bool ACommonMapController::HasTask() const noexcept
{
    return this->m_o_task && this->m_o_task->IsValidLowLevelFast();
}

bool ACommonMapController::OverrideTask( UExcutableTask* task )
{
    this->CancelCreatingTask();
    this->m_o_task = task;
    return true;
}

void ACommonMapController::ReleaseFinishedTask()
{
    if( !this->m_o_task || !this->m_o_task->IsValidLowLevelFast() || (this->m_o_task->GetStep() != ETaskStep::FINISHED) )
    {
        return;
    }
    this->m_o_task->RemoveFromRoot();
    this->m_o_task = nullptr;
}

UExcutableTask* ACommonMapController::GetTask() const noexcept
{
    return this->m_o_task;
}

bool ACommonMapController::IsViewportEdgeLocked( const EViewportEdge side ) const noexcept
{
    auto lock = this->m_map_viewport_edge_lock.find( side );
    return (lock == this->m_map_viewport_edge_lock.end()) || lock->second;
}

void ACommonMapController::MoveTowardsViewportEdge( const EViewportEdge side )
{
    auto pawn = this->IsViewportEdgeLocked( side ) ? nullptr : Cast<ACommonMapViewer>( this->GetPawn() );
    if( !pawn )
    {
        return;
    }
    float stepVolume = 1.0f;
    switch( side )
    {
    case EViewportEdge::TOP:
        pawn->MoveForward( stepVolume );
        break;
    case EViewportEdge::BOTTOM:
        pawn->MoveForward( -1 * stepVolume );
        break;
    case EViewportEdge::LEFT:
        pawn->MoveRight( -1 * stepVolume );
        break;
    case EViewportEdge::RIGHT:
        pawn->MoveRight( stepVolume );
        break;
    default:
        return;
    }
}

void ACommonMapController::SetEdgeLock( EViewportEdge side, bool lock )
{
    auto elem = this->m_map_viewport_edge_lock.find( side );
    if( elem != this->m_map_viewport_edge_lock.end() )
    {
        elem->second = lock;
    }
}
