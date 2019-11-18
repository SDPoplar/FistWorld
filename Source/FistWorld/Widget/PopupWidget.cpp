// Fill out your copyright notice in the Description page of Project Settings.

#include "PopupWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Controllers/ModeOverridableController.h"

UPopupWidget::UPopupWidget( const FObjectInitializer& ObjectInitializer ) : UUserWidget( ObjectInitializer ),
    popupVisibilily( ESlateVisibility::Visible )
{
    Visibility = ESlateVisibility::Collapsed;
}

void UPopupWidget::Quit()
{
    APlayerController* pc = nullptr;
    if( this->m_override_mouse.setted )
    {
        this->GetPlayerController( pc );
        pc->bShowMouseCursor = this->m_override_mouse.origin;
    }
    if( this->m_b_override_input_mode )
    {
        AModeOverridableController* oc = Cast<AModeOverridableController>( this->GetPlayerController( pc ) );
        if( oc )
        {
            oc->PopInputMode();
        }
    }
    this->SetVisibility( ESlateVisibility::Collapsed );
}

void UPopupWidget::Popup()
{
    if( this->IsInShow() )
    {
        UE_LOG( LogTemp, Display, TEXT( "Cancel display widget: %s" ), *( this->GetName() ) );
        return;
    }
    this->SetVisibility( this->popupVisibilily );
    UE_LOG( LogTemp, Display, TEXT( "Widget [%s] visibility setted" ), *( this->GetName() ) );
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
    AModeOverridableController* oc = Cast<AModeOverridableController>( this->GetPlayerController( pc ) );
    this->m_b_override_input_mode = oc && this->OverrideInputMode( oc );
}

bool UPopupWidget::OverrideInputMode( AModeOverridableController* oc )
{
    return false;
}

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

bool UPopupWidget::IsInShow( void ) const noexcept
{
    return this->IsInViewport() && (this->Visibility != ESlateVisibility::Collapsed);
}
