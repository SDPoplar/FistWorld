// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldMapMode.h"
#include "Huds/WorldMapHud.h"

AWorldMapMode::AWorldMapMode()
{
    HUDClass = AWorldMapHud::StaticClass();
}
