// Fill out your copyright notice in the Description page of Project Settings.

#include "PopupWidget.h"
#include "Kismet/GameplayStatics.h"

/*
UPopupWidget::UPopupWidget( const FObjectInitializer& ObjectInitializer )
{
    UUserWidget( ObjectInitializer );
}
*/

/*
UPopupWidget* UPopupWidget::Popup( UWorld* world )
{
    UPopupWidget *widget = CreateWidgetInstance( world, )
}

*/
void UPopupWidget::Quit()
{
    APlayerController* pc = nullptr;
    if( this->m_override_mouse.setted )
    {
        this->GetPlayerController( pc );
        pc->bShowMouseCursor = this->m_override_mouse.origin;
    }
    this->RemoveFromViewport();
}

void UPopupWidget::Popup( int baseZOrder )
{
    this->AddToViewport( baseZOrder + 100 );
    this->RefreshData();

    APlayerController* pc = nullptr;

    bool smc;
    if( this->OverrideShowMouseCursor( smc ) && ( this->GetPlayerController( pc )
        && pc->bShowMouseCursor != smc ) )
    {
        this->m_override_mouse.setted = true;
        this->m_override_mouse.origin = pc->bShowMouseCursor;
        pc->bShowMouseCursor = smc;
    }
    else
    {
        this->m_override_mouse.setted = false;
        this->m_override_mouse.origin = false;
    }
}

/*
bool UPopupWidget::OverrideInputMode()
{}
*/

bool UPopupWidget::OverrideShowMouseCursor( bool& showMouseCursor )
{
    return false;
}

APlayerController* UPopupWidget::GetPlayerController( APlayerController* &pc )
{
    if( !pc )
    {
        pc = UGameplayStatics::GetPlayerController( this, 0 );
    }
    return pc;
}
