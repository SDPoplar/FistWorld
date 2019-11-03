// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine.h"
#include "FistWorldInstance.h"
//  #include "Widget/PopupMenuWidget.h"
//  #include "UObject/ConstructorHelpers.h"

/*
UMainMenu::UMainMenu( const FObjectInitializer& ObjectInitializer )
{
    //  Super( ObjectInitializer );
    static ConstructorHelpers::FClassFinder<UPopupMenuWidget> about( TEXT( "/Game/Levels/Res_lv_MainMenu/Widget_About" ) );
    this->aboutWidgetClass = about.Succeeded() ? about.Class : nullptr;
    static ConstructorHelpers::FClassFinder<UPopupMenuWidget> create( TEXT( "/Game/Levels/Res_lv_MainMenu/Widget_CreateGame" ) );
    this->createGameWidgetClass = create.Succeeded() ? create.Class : nullptr;
}
*/

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

void UMainMenu::ShowAboutWidget()
{
    if( !this->aboutWidget )
    {
        //  this->aboutWidget = this->CreatePopupMenu( this->aboutWidgetClass, FName( "About game" ) );
        /*
        this->aboutWidget = this->CreatePopupMenu(
            LoadClass<UPopupMenuWidget>( this, TEXT( "/Game/Levels/Res_lv_MainMenu/Widget_About_C" ) )
            ->StaticClass(), FName( "About" ) );
            */
        this->aboutWidget = this->MakeAboutWidget( UGameplayStatics::GetPlayerController( this, 0 ) );
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
        //  this->createGameWidget = this->CreatePopupMenu( this->createGameWidgetClass, FName( "Create game" ) );
        /*
        this->createGameWidget = this->CreatePopupMenu(
            LoadClass<UPopupMenuWidget>( this, TEXT( "/Game/Levels/Res_lv_MainMenu/Widget_CreateGame_C.Widget_CreateGame_C" ) )
            ->StaticClass(), FName( "Create game" ) );
            */
        this->createGameWidget = this->MakeCreateGameWidget( UGameplayStatics::GetPlayerController( this, 0 ) );
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
        this->optionWidget = this->MakeOptionWidget( UGameplayStatics::GetPlayerController( this, 0 ) );
    }
    if( this->optionWidget )
    {
        this->optionWidget->Popup();
    }
}

/*
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
*/
