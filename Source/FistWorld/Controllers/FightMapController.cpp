// Copyright 2019

#include "FightMapController.h"
#include "GameModes/TownFightMode.h"

void AFightMapController::BeginPlay()
{
    Super::BeginPlay();

    this->bShowMouseCursor = true;
    FInputModeGameAndUI mode;
    this->PushInputMode( mode );

    //  move fight start to level actor ?
    auto gm = ATownFightMode::Get( this );
    gm->LoadFirstFight();
}
