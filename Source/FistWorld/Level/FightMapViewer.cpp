// Copyright 2019

#include "FightMapViewer.h"
#include "Components/InputComponent.h"

AFightMapViewer::AFightMapViewer() : ACommonMapViewer()
{}

void AFightMapViewer::SetupPlayerInputComponent( UInputComponent* PlayerInputComponent )
{
    ACommonMapViewer::SetupPlayerInputComponent( PlayerInputComponent );

    PlayerInputComponent->BindAxis( "ZoomCamera", this, &AFightMapViewer::ZoomCamera );
    PlayerInputComponent->BindAction( "ResetCamera", IE_Released, this, &AFightMapViewer::ResetCamera );
}
