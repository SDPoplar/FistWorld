// Fill out your copyright notice in the Description page of Project Settings.

#include "CommonMapHud.h"
//  #include "Widget/PopupWidget.h"
#include "Widget/SysMenuWidget.h"
//  #include "Widget/MessageBoxWidget.h"
#include "UObject/ConstructorHelpers.h"

ACommonMapHud::ACommonMapHud( const FObjectInitializer& ObjectInitializer ) : AHUD( ObjectInitializer ),
    m_widget_sysmenu( nullptr ), m_widget_message( nullptr )
{
    static ConstructorHelpers::FClassFinder<UMessageBoxWidget> msgboxwidget( TEXT( "/Game/Levels/Res_lv_Common/Widget_Common_MessageBox" ) );
    msgboxClass = msgboxwidget.Succeeded() ? msgboxwidget.Class : nullptr;
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

bool ACommonMapHud::PopupMessage( EMessageUseIcon type, FString content )
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

bool ACommonMapHud::PopupAlert( FString content )
{
    return this->PopupMessage( EMessageUseIcon::ALERT, content );
}

void ACommonMapHud::PopupWidget( UPopupWidget* widget )
{
    this->m_widgets.AddUnique( widget );
    widget->Popup();
}
