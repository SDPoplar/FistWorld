// Copyright 2019

#include "MessageBoxWidget.h"

UMessageBoxWidget::UMessageBoxWidget( const FObjectInitializer& ObjectInitializer ) : UPopupWidget( ObjectInitializer )
{}

void UMessageBoxWidget::SetDisplayContent( EMessageUseIcon type, FText content )
{
    this->m_e_type = type;
    this->m_s_content = content;
    this->m_display_time = time( nullptr );
}

FText UMessageBoxWidget::GetContent() const noexcept
{
    return ( this->IsValidLowLevelFast() && this->IsInViewport() ) ? this->m_s_content : FText::FromString( "" );
}

EMessageUseIcon UMessageBoxWidget::GetType() const noexcept
{
    return ( this->IsValidLowLevelFast() && this->IsInViewport() ) ? this->m_e_type : EMessageUseIcon::ALERT;
}

void UMessageBoxWidget::CheckLifetime()
{
    if( time( nullptr ) - this->m_display_time > this->lifeTime )
    {
        this->Quit();
    }
}
