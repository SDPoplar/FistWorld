// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine.h"
#include "FistWorldInstance.h"
#include "Widget/CreateGameWidget.h"
//  #include "Widget/PopupMenuWidget.h"
#include "UObject/ConstructorHelpers.h"

UMainMenu::UMainMenu( const FObjectInitializer& ObjectInitializer ) : UUserWidget( ObjectInitializer ),
    aboutWidget( nullptr ), optionWidget( nullptr ), createGameWidget( nullptr )
{
    static ConstructorHelpers::FClassFinder<UCreateGameWidget> create( TEXT( "/Game/Levels/Res_lv_MainMenu/Widget_CreateGame" ) );
    creategameClass = create.Succeeded() ? create.Class : nullptr;
    static ConstructorHelpers::FClassFinder<UPopupMenuWidget> about( TEXT( "/Game/Levels/Res_lv_MainMenu/Widget_About" ) );
    aboutwidgetClass = about.Succeeded() ? about.Class : nullptr;
    static ConstructorHelpers::FClassFinder<UPopupMenuWidget> setting( TEXT( "/Game/Levels/Res_lv_MainMenu/Widget_Options" ) );
    optionwidgetClass = setting.Succeeded() ? setting.Class : nullptr;
}

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
    UGameplayStatics::OpenLevel( this, "LV_World" );
}

void UMainMenu::ShowAboutWidget()
{
    if( !this->aboutWidget && this->aboutwidgetClass )
    {
        UWorld* world = this->GetWorld();
        this->aboutWidget = Cast<UPopupMenuWidget>( UUserWidget::CreateWidgetInstance( *world, this->aboutwidgetClass, "About widget" ) );
        this->aboutWidget->AddToViewport( 10 );
    }
    if( this->aboutWidget )
    {
        this->aboutWidget->Popup();
    }
}

void UMainMenu::ShowCreateGameWidget()
{
    if( !this->createGameWidget )
    {
        UWorld* world = this->GetWorld();
        this->createGameWidget = Cast<UCreateGameWidget>( UUserWidget::CreateWidgetInstance( *world, this->creategameClass, "Create game" ) );
        if( this->createGameWidget )
        {
            this->createGameWidget->AddToViewport( 10 );
            this->createGameWidget->BindParent( this );
        }
    }
    if( this->createGameWidget )
    {
        this->createGameWidget->Popup();
        this->createGameWidget->RefreshChapter();
    }
}

void UMainMenu::ShowOptionWidget()
{
    if( !this->optionWidget )
    {
        UWorld* world = this->GetWorld();
        this->optionWidget = Cast<UPopupMenuWidget>( UUserWidget::CreateWidgetInstance( *world, this->optionwidgetClass, "Options widget" ) );
        this->optionWidget->AddToViewport( 10 );
    }
    if( this->optionWidget )
    {
        this->optionWidget->Popup();
    }
}

void UMainMenu::BtnContinueClicked( void )
{
    auto gi = UFistWorldInstance::GetInstance( this );
    if( gi->LoadGame() )
    {
        this->StartExistsGame();
    }
}
