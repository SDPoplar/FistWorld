// Copyright 2019

#include "FightMapController.h"
#include "GameModes/TownFightMode.h"
#include "Kismet/GameplayStatics.h"

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

AFightMapController* AFightMapController::Get( UObject* getter )
{
    return Cast<AFightMapController>( UGameplayStatics::GetPlayerController( getter, 0 ) );
}

AFightMapHud* AFightMapController::GetFightHud()
{
    return Cast<AFightMapHud>( this->GetHUD() );
}
