// Copyright 2019

#include "FightMapViewer.h"
#include "Components/InputComponent.h"

AFightMapViewer::AFightMapViewer() : ACommonMapViewer()
{
    this->m_f_def_arm_len = 800;
}

void AFightMapViewer::SetupPlayerInputComponent( UInputComponent* PlayerInputComponent )
{
    ACommonMapViewer::SetupPlayerInputComponent( PlayerInputComponent );

    PlayerInputComponent->BindAxis( "ZoomCamera", this, &AFightMapViewer::ZoomCamera );
}
