// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuMode.h"
#include "Controllers/MenuController.h"
#include "Kismet/GameplayStatics.h"

AMenuMode::AMenuMode()
{
    this->PlayerControllerClass = AMenuController::StaticClass();
}

void AMenuMode::StartPlay()
{
    AGameModeBase::StartPlay();

    auto pc = UGameplayStatics::GetPlayerController( this, 0 );
    pc->bShowMouseCursor = true;
    FInputModeUIOnly mode;
    pc->SetInputMode( mode );
}