// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldMapMode.h"
#include "Huds/WorldMapHud.h"
#include "Level/WorldMapViewer.h"
#include "Controllers/WorldMapController.h"

AWorldMapMode::AWorldMapMode()
{
    HUDClass = AWorldMapHud::StaticClass();
    DefaultPawnClass = AWorldMapViewer::StaticClass();
    PlayerControllerClass = AWorldMapController::StaticClass();
}
