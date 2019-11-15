// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine.h"
#include "FistWorldInstance.h"
#include "Widget/CreateGameWidget.h"
//  #include "Widget/PopupMenuWidget.h"
//  #include "UObject/ConstructorHelpers.h"

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
    auto browseResult = gi->GetEngine()->Browse( *( gi->GetWorldContext() ), TEXT( "LV_World" ), err );
    if( browseResult != EBrowseReturnVal::Success )
    {
        UE_LOG( LogTemp, Error, TEXT( "Browse LV_World failed: %s" ), *err );
    }
}

void UMainMenu::ShowAboutWidget()
{
    if( !this->aboutWidget )
    {
        TSubclassOf<UPopupMenuWidget> widgetClass = LoadClass<UPopupMenuWidget>( nullptr,
            TEXT( "PopupMenuWidget'/Game/Levels/Res_lv_MainMenu/Widget_About.Widget_About_C'" ) );
        check( widgetClass && "Cannot find Widget_About" );
        this->aboutWidget = this->CreatePopupMenu( widgetClass, FName( "Copyright Widget" ) );
        check( this->aboutWidget && "Failed to create widget_about" );
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
        TSubclassOf<UCreateGameWidget> widgetClass = LoadClass<UCreateGameWidget>( nullptr,
            TEXT( "CreateGameWidget'/Game/Levels/Res_lv_MainMenu/Widget_CreateGame.Widget_CreateGame_C'" ) );
        this->createGameWidget = Cast<UCreateGameWidget>( this->CreatePopupMenu( widgetClass, FName( "Create game widget" ) ) );
        if( this->createGameWidget )
        {
            this->createGameWidget->BindParent( this );
        }
    }
    if( this->createGameWidget )
    {
        this->createGameWidget->Popup();
    }
}

void UMainMenu::ShowOptionWidget()
{
    if( !this->optionWidget )
    {
        TSubclassOf<UPopupMenuWidget> widgetClass = LoadClass<UPopupMenuWidget>( nullptr,
            TEXT( "PopupMenuWidget'/Game/Levels/Res_lv_MainMenu/Widget_Options.Widget_Options_C'" ) );
        this->optionWidget = this->CreatePopupMenu( widgetClass, FName( "Options widget" ) );
    }
    if( this->optionWidget )
    {
        this->optionWidget->Popup();
    }
}

UPopupMenuWidget* UMainMenu::CreatePopupMenu( TSubclassOf<UPopupMenuWidget> cls, FName name )
{
    if( !cls )
    {
        return nullptr;
    }
    auto ps = UGameplayStatics::GetPlayerController( this, 0 );
    auto widget = UMainMenu::CreateWidgetInstance( *ps, cls, name );
    return Cast<UPopupMenuWidget>( widget );
}

void UMainMenu::BtnContinueClicked( void )
{
    auto gi = UFistWorldInstance::GetInstance( this );
    if( gi->LoadGame() )
    {
        this->StartExistsGame();
    }
}
