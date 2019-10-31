// Fill out your copyright notice in the Description page of Project Settings.

#include "FistWorldSave.h"
#include "Kismet/GameplayStatics.h"
#include "FistWorldInstance.h"

const FString UFistWorldSave::SaveSlotName = TEXT( "fistworld" );

bool UFistWorldSave::FileExists( void )
{
    return UGameplayStatics::DoesSaveGameExist( UFistWorldSave::SaveSlotName, 0 );
}

UFistWorldSave* UFistWorldSave::LoadSave()
{
    return UFistWorldSave::FileExists()
        ? Cast<UFistWorldSave>( UGameplayStatics::LoadGameFromSlot( UFistWorldSave::SaveSlotName, 0 ) )
        : nullptr;
}
