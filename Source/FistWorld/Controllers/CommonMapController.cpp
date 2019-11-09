// Fill out your copyright notice in the Description page of Project Settings.


#include "CommonMapController.h"
#include "Huds/CommonMapHud.h"

void ACommonMapController::BeginPlay()
{
    this->bEnableClickEvents = true;
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
    return false;
}
