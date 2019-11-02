// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuMode.h"
#include "Kismet/GameplayStatics.h"
#include "Controllers/MenuController.h"
#include "Huds/MainMenuHud.h"

AMenuMode::AMenuMode()
{
    this->PlayerControllerClass = AMenuController::StaticClass();
    this->HUDClass = AMainMenuHud::StaticClass();
}

void AMenuMode::StartPlay()
{
    AGameModeBase::StartPlay();

    auto pc = UGameplayStatics::GetPlayerController( this, 0 );
    pc->bShowMouseCursor = true;
    FInputModeUIOnly mode;
    pc->SetInputMode( mode );
}