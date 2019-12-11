// Fill out your copyright notice in the Description page of Project Settings.

#include "ExcutableTask.h"
#include "Static/Lang/TaskStep.h"
#include "Kismet/GameplayStatics.h"
#include "Huds/CommonMapHud.h"

UExcutableTask::UExcutableTask( const FObjectInitializer& ObjectInitializer ) : UObject( ObjectInitializer ),
    m_o_hud( nullptr ), m_e_step( ETaskStep::CREATING ), m_b_create_by_ai( true )
{
    this->AddToRoot();
}

UExcutableTask::~UExcutableTask()
{}

void UExcutableTask::MarkAsPlayerCreate()
{
    this->m_b_create_by_ai = false;
    auto pc = UGameplayStatics::GetPlayerController( this, 0 );
    this->m_o_hud = Cast<ACommonMapHud>( pc ? pc->GetHUD() : nullptr );
}

bool UExcutableTask::Excute()
{
    return true;
}

FText UExcutableTask::GetStepDescribe() const
{
    switch( this->m_e_step )
    {
    case ETaskStep::CREATING:
        return txtCreating;
    case ETaskStep::CHOOSING_TARGET_TOWN:
        return txtChooseTargetTown;
    case ETaskStep::CHOOSING_TARGET_WARRIOR:
        return txtChooseWarrior;
    case ETaskStep::SETTING_TRANSPORT_VOLUME:
        return txtSetTransform;
    case ETaskStep::SETTING_SOLDIER_NUMBER:
        return txtSetSoldierNum;
    case ETaskStep::FINISHED:
        return txtFinished;
    case ETaskStep::CANCELED:
        return txtCanceled;
    }
    return txtUnkown;
}

void UExcutableTask::MarkAsFinished() noexcept
{
    this->m_e_step = ETaskStep::FINISHED;
    this->RemoveFromRoot();
}

void UExcutableTask::MarkAsCanceled() noexcept
{
    this->m_e_step = ETaskStep::CANCELED;
    this->RemoveFromRoot();
}

ETaskStep UExcutableTask::GetStep() const noexcept
{
    return this->m_e_step;
}

bool UExcutableTask::NeedDisplayStep() const noexcept
{
    return false
        || (this->m_e_step == ETaskStep::CHOOSING_TARGET_TOWN)
        || false;
}

bool UExcutableTask::CanCancel( void ) const noexcept
{
    return true
        && (this->m_e_step != ETaskStep::FINISHED)
        && (this->m_e_step != ETaskStep::CANCELED)
        && true;
}

bool UExcutableTask::ShowNotice( FText content )
{
    return !this->m_b_create_by_ai && this->m_o_hud && this->m_o_hud->PopupAlert( content );
}

bool UExcutableTask::ShowError( FText message )
{
    return !this->m_b_create_by_ai && this->m_o_hud && this->m_o_hud->PopupFailed( message );
}
