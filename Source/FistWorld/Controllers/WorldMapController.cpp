// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldMapController.h"
#include "Kismet/GameplayStatics.h"
#include "Level/TownActor.h"
#include "Huds/WorldMapHud.h"

void AWorldMapController::BeginPlay()
{
    Super::BeginPlay();

    this->bShowMouseCursor = true;
    FInputModeGameAndUI mode;
    this->PushInputMode( mode );
}

void AWorldMapController::SetupInputComponent()
{
    Super::SetupInputComponent();
}

AWorldMapController* AWorldMapController::GetInstance( UObject* getter )
{
    return Cast<AWorldMapController>( UGameplayStatics::GetPlayerController( getter, 0 ) );
}

bool AWorldMapController::CancelCreatingTask()
{
    return false;
}

bool AWorldMapController::HasTaskSelectingTown() const
{
    return false;
}

void AWorldMapController::SetTaskSelectingTown( ATownActor* town )
{}

AWorldMapHud* AWorldMapController::GetWorldMapHud()
{
    return Cast<AWorldMapHud>( this->GetHUD() );
}
