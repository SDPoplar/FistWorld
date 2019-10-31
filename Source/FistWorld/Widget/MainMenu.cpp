// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine.h"
#include "FistWorldInstance.h"

bool UMainMenu::HasGame( void ) const
{
    return UFistWorldInstance::GetInstance( this )->HasGame();
}

void UMainMenu::ExitGame()
{
    UKismetSystemLibrary::QuitGame( this, UGameplayStatics::GetPlayerController( this, 0 ), EQuitPreference::Quit, true );
}

void UMainMenu::StartExistsGame()
{
    FString err;
    auto gi = UFistWorldInstance::GetInstance( this );
    gi->GetEngine()->Browse( *( gi->GetWorldContext() ), TEXT( "LV_World" ), err );
}
