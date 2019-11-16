// Fill out your copyright notice in the Description page of Project Settings.

#include "CommonMapHud.h"
//  #include "Widget/PopupWidget.h"
#include "Widget/SysMenuWidget.h"
//  #include "Widget/MessageBoxWidget.h"
#include "UObject/ConstructorHelpers.h"

ACommonMapHud::ACommonMapHud( const FObjectInitializer& ObjectInitializer ) : AHUD( ObjectInitializer ),
    m_widget_sysmenu( nullptr ), m_widget_message( nullptr )
{
    static ConstructorHelpers::FClassFinder<USysMenuWidget> sysmenufinder( TEXT( "/Game/Levels/Res_lv_World/Widget_World_SysMenu" ) );
    sysmenuClass = sysmenufinder.Succeeded() ? sysmenufinder.Class : nullptr;
    check( sysmenuClass && "Failed to load sysmenuClass" );
    static ConstructorHelpers::FClassFinder<UMessageBoxWidget> msgboxwidget( TEXT( "/Game/Levels/Res_lv_Common/Widget_Common_MessageBox" ) );
    msgboxClass = msgboxwidget.Succeeded() ? msgboxwidget.Class : nullptr;
    check( msgboxClass && "Messagebox class not found" );
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
    }
    return this->m_widget_sysmenu;
}

UMessageBoxWidget* ACommonMapHud::GetMessageBox()
{
    if( !this->msgboxClass )
    {
        return nullptr;
    }
    if( !this->m_widget_message /*|| !this->m_widget_message->IsValidLowLevelFast()*/ )
    {
        /*
        TSubclassOf<UMessageBoxWidget> widgetClass = LoadClass<UMessageBoxWidget>( nullptr,
            TEXT( "/Game/Levels/Res_lv_Common/Widget_Common_MessageBox.Widget_Common_MessageBox_C" ) );
            */
        UWorld* world = this->GetWorld();
        if( !world )
        {
            UE_LOG( LogTemp, Error, TEXT( "Cannot get world in hud::getMessageBox" ) );
        }
        this->m_widget_message = Cast<UMessageBoxWidget>( UUserWidget::CreateWidgetInstance( *world, this->msgboxClass, "MessageBox" ) );
    }
    return this->m_widget_message;
}

bool ACommonMapHud::CloseAllPopup()
{
    int closed = 0;
    while( this->m_widgets.Num() )
    {
        if( this->m_widgets[ 0 ]->IsValidLowLevelFast() && this->m_widgets[ 0 ]->IsInViewport() )
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
    this->PopupWidget( msgbox, 100 );
    return true;
}

bool ACommonMapHud::PopupAlert( FString content )
{
    return this->PopupMessage( EMessageUseIcon::ALERT, content );
}

void ACommonMapHud::PopupWidget( UPopupWidget* widget, int zOrder )
{
    this->m_widgets.AddUnique( widget );
    widget->Popup( zOrder );
}
