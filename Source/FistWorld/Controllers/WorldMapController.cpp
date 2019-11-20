// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldMapController.h"
#include "FistWorldInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Level/TownActor.h"
#include "Huds/WorldMapHud.h"
#include "Tasks/ExcutableTask.h"
#include "Tasks/SingleWarriorTownTask.h"
#include "Story/Warrior.h"

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

bool AWorldMapController::HasTaskSelectingTown() const
{
    return this->HasTask() && ( this->m_o_task->GetStep() == ETaskStep::CHOOSING_TARGET_TOWN );
}

bool AWorldMapController::SetTaskSelectingTown( ATownActor* town )
{
    auto task = Cast<UTownTask>( this->GetTask() );
    return task && ( task->GetStep() == ETaskStep::CHOOSING_TARGET_TOWN ) && task->SetTargetTown( town->GetTown() );
}

bool AWorldMapController::SetTaskSelectingWarrior( UWarriorIns* warriorIns )
{
    auto gi = UFistWorldInstance::GetInstance( this );
    auto warrior = gi ? gi->FindWarrior( warriorIns->GetWarriorId() ) : nullptr;
    auto task = warrior ? Cast<USingleWarriorTownTask>( this->m_o_task ) : nullptr;
    return task && task->SetTargetWarrior( warrior );
}

AWorldMapHud* AWorldMapController::GetWorldMapHud()
{
    return Cast<AWorldMapHud>( this->GetHUD() );
}
