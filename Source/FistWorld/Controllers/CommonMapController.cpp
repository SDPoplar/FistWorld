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

    UE_LOG( LogTemp, Display, TEXT( "Binding Escape" ) );
    this->InputComponent->BindAction( "PressEscape", IE_Released, this, &ACommonMapController::CancelOrCallSysMenu );
}

void ACommonMapController::CancelOrCallSysMenu()
{
    UE_LOG( LogTemp, Display, TEXT( "Escape pressed" ) );
    auto hud = Cast<ACommonMapHud>( this->GetHUD() );
    if( !(hud && (hud->CloseAllPopup() || hud->ShowSysMenu())) )
    {
        UE_LOG( LogTemp, Error, TEXT( "Failed to show system menu" ) );
    }
}
