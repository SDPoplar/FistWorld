// Copyright 2019

#include "TownFightMode.h"
#include "Controllers/FightMapController.h"
#include "Huds/FightMapHud.h"

ATownFightMode::ATownFightMode()
{
    PlayerControllerClass = AFightMapController::StaticClass();
    HUDClass = AFightMapHud::StaticClass();
}
