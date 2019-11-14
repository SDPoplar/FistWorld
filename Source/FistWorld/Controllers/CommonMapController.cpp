// Fill out your copyright notice in the Description page of Project Settings.


#include "CommonMapController.h"
#include "Huds/CommonMapHud.h"
#include "Tasks/ExcutableTask.h"

void ACommonMapController::BeginPlay()
{
    this->bEnableClickEvents = true;
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
    if( !this->HasTask() )
    {
        return false;
    }
    delete this->m_o_task;
    this->m_o_task = nullptr;
    return true;
}

bool ACommonMapController::HasTask() const noexcept
{
    return !!this->m_o_task;
}

bool ACommonMapController::OverrideTask( UExcutableTask* task )
{
    this->CancelCreatingTask();
    this->m_o_task = task;
    return true;
}

FString ACommonMapController::GetTaskStepDescribe() const
{
    return this->HasTask() ? this->m_o_task->GetStepDescribe() : FString( "" );
}