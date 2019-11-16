// Copyright 2019

#include "TownSearchTask.h"
#include "Huds/CommonMapHud.h"
#include "Controllers/WorldMapController.h"
#include "Story/Town.h"
#include "Kismet/GameplayStatics.h"

UTownSearchTask::UTownSearchTask( const FObjectInitializer& ObjectInitializer ) : UTownTask( ObjectInitializer )
{}

bool UTownSearchTask::SetTargetWarrior( UWarrior* warrior )
{
    return UTownTask::SetTargetWarrior( warrior ) && this->Excute();
}

bool UTownSearchTask::Excute()
{
    if( !this->m_o_town || !this->m_o_warrior )
    {
        return false;
    }
    //  TODO: find something
    auto pc = UGameplayStatics::GetPlayerController( this, 0 );
    if( !pc )
    {
        UE_LOG( LogTemp, Error, TEXT( "Cannot get player controller" ) );
    }
    auto hud = pc ? Cast<ACommonMapHud>( pc->GetHUD() ) : nullptr;
    if( !hud )
    {
        UE_LOG( LogTemp, Error, TEXT( "Cannot get hud" ) );
        return false;
    }
    hud->PopupAlert( "100 money found" );
    this->m_o_town->IncreaseMoney( 100 );
    return true;
}
