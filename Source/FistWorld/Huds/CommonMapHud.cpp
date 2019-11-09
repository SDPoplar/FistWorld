// Fill out your copyright notice in the Description page of Project Settings.

#include "CommonMapHud.h"
//  #include "Widget/PopupWidget.h"
#include "Widget/SysMenuWidget.h"

/*
ACommonMapHud::ACommonMapHud() : Super(), m_widget_sysmenu( nullptr )
{}
*/

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

void ACommonMapHud::PopupWidget( UPopupWidget* widget )
{
    this->m_widgets.AddUnique( widget );
    widget->Popup();
}
