// Fill out your copyright notice in the Description page of Project Settings.

#include "CommonMapHud.h"
//  #include "Widget/PopupWidget.h"
#include "Widget/SysMenuWidget.h"
//  #include "Widget/MessageBoxWidget.h"
#include "Widget/ConfirmBackWidget.h"
#include "UObject/ConstructorHelpers.h"

ACommonMapHud::ACommonMapHud( const FObjectInitializer& ObjectInitializer ) : AHUD( ObjectInitializer ),
    m_widget_sysmenu( nullptr ), m_widget_message( nullptr ), m_widget_confirm_back( nullptr )
{
    static ConstructorHelpers::FClassFinder<UMessageBoxWidget> msgboxwidget( TEXT( "/Game/Levels/Res_lv_Common/Widget_Common_MessageBox" ) );
    msgboxClass = msgboxwidget.Succeeded() ? msgboxwidget.Class : nullptr;

    static ConstructorHelpers::FClassFinder<UUserWidget> edge( TEXT( "/Game/Levels/Res_lv_Common/Widget_Common_ViewportEdge" ) );
    edgeClass = edge.Succeeded() ? edge.Class : nullptr;
}

void ACommonMapHud::BeginPlay()
{
    Super::BeginPlay();

    UWorld* world = this->GetWorld();
    auto edge = UUserWidget::CreateWidgetInstance( *world, edgeClass, "viewport edge" );
    if( edge )
    {
        UE_LOG( LogTemp, Display, TEXT( "Viewport Edge loaded" ) );
        edge->AddToViewport();
    }
    else
    {
        UE_LOG( LogTemp, Error, TEXT( "Failed to load viewport edge" ) );
    }
}

USysMenuWidget* ACommonMapHud::GetSysMenu()
{
    if( !this->sysmenuClass )
    {
        return nullptr;
    }
    if( !this->m_widget_sysmenu )
    {
        UWorld* world = this->GetWorld();
        this->m_widget_sysmenu = Cast<USysMenuWidget>( UUserWidget::CreateWidgetInstance( *world, this->sysmenuClass, "SysMenu" ) );
        this->m_widget_sysmenu->AddToViewport( 100 );
    }
    return this->m_widget_sysmenu;
}

UMessageBoxWidget* ACommonMapHud::GetMessageBox()
{
    if( !this->msgboxClass )
    {
        return nullptr;
    }
    if( !this->m_widget_message )
    {
        UWorld* world = this->GetWorld();
        if( !world )
        {
            UE_LOG( LogTemp, Error, TEXT( "Cannot get world in hud::getMessageBox" ) );
        }
        this->m_widget_message = Cast<UMessageBoxWidget>( UUserWidget::CreateWidgetInstance( *world, this->msgboxClass, "MessageBox" ) );
        this->m_widget_message->AddToViewport( 101 );
    }
    return this->m_widget_message;
}

UConfirmBackWidget* ACommonMapHud::GetConfirmBackWidget()
{
    if( !this->m_widget_confirm_back && this->confirmbackClass )
    {
        UWorld* world = this->GetWorld();
        this->m_widget_confirm_back = Cast<UConfirmBackWidget>(
            UUserWidget::CreateWidgetInstance( *world, this->confirmbackClass, "Confirm back" ) );
        this->m_widget_confirm_back->AddToViewport( 101 );
    }
    return this->m_widget_confirm_back;
}


bool ACommonMapHud::CloseAllPopup()
{
    int closed = 0;
    while( this->m_widgets.Num() )
    {
        if( this->m_widgets[ 0 ]->IsInShow() )
        {
            this->m_widgets[ 0 ]->Quit();
            closed++;
        }
        this->m_widgets.RemoveAt( 0 );
    }
    return !!closed;
}

bool ACommonMapHud::ShowSysMenu()
{
    auto sysmenu = this->GetSysMenu();
    if( !sysmenu )
    {
        return false;
    }
    this->PopupWidget( sysmenu );
    return true;
}

bool ACommonMapHud::PopupConfirmBackWidget()
{
    auto widget = this->GetConfirmBackWidget();
    if( !widget )
    {
        return false;
    }
    this->PopupWidget( widget );
    return true;
}

bool ACommonMapHud::PopupMessage( EMessageUseIcon type, FText content )
{
    auto msgbox = this->GetMessageBox();
    if( !msgbox )
    {
        UE_LOG( LogTemp, Error, TEXT( "Failed to create messagebox" ) );
        return false;
    }
    msgbox->SetDisplayContent( type, content );
    this->PopupWidget( msgbox );
    return true;
}

bool ACommonMapHud::PopupAlert( FText content )
{
    return this->PopupMessage( EMessageUseIcon::ALERT, content );
}

bool ACommonMapHud::PopupSuccess( FText content )
{
    return this->PopupMessage( EMessageUseIcon::SUCCESS, content );
}

bool ACommonMapHud::PopupFailed( FText content )
{
    return this->PopupMessage( EMessageUseIcon::FAILED, content );
}

void ACommonMapHud::PopupWidget( UPopupWidget* widget )
{
    this->m_widgets.AddUnique( widget );
    widget->Popup();
}
