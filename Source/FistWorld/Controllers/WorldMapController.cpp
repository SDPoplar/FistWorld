// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldMapController.h"

void AWorldMapController::BeginPlay()
{
    Super::BeginPlay();

    this->bShowMouseCursor = true;
    FInputModeGameAndUI mode;
    this->SetInputMode( mode );
}
