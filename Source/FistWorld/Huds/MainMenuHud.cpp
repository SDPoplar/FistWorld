// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuHud.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "FistWorldInstance.h"
#include "UserWidget.h"

AMainMenuHud::AMainMenuHud() : AHUD()
{
    static ConstructorHelpers::FClassFinder<UUserWidget> mainmenu( TEXT( "/Game/Levels/Res_lv_MainMenu/Widget_MainMenu" ) );
    this->mainMenuClass = mainmenu.Succeeded() ? mainmenu.Class : nullptr;
}

void AMainMenuHud::BeginPlay()
{
    Super::BeginPlay();

    auto pc = UGameplayStatics::GetPlayerController( this, 0 );
    UUserWidget* mainMenu = UUserWidget::CreateWidgetInstance( *pc, this->mainMenuClass, FName( "MainMenu" ) );
    if( mainMenu )
    {
        mainMenu->AddToViewport();
    }
}
