// Copyright 2019

#include "MessageBoxWidget.h"

UMessageBoxWidget::UMessageBoxWidget( const FObjectInitializer& ObjectInitializer )
    : UPopupWidget( ObjectInitializer ), m_f_display_time( 0.0f )
{}

void UMessageBoxWidget::SetDisplayContent( EMessageUseIcon type, FText content )
{
    if( this->messages.Num() == 0 )
    {
        this->m_f_display_time = this->GetWorld()->GetRealTimeSeconds();
    }
    this->messages.Add( FMessageContent( type, content ) );
}

FText UMessageBoxWidget::GetContent() const noexcept
{
    return this->messages.Num() ? this->messages[ 0 ].content : FText::GetEmpty();
}

EMessageUseIcon UMessageBoxWidget::GetType() const noexcept
{
    return this->messages.Num() ? this->messages[ 0 ].type : EMessageUseIcon::ALERT;
}

void UMessageBoxWidget::CheckLifetime()
{
    auto now = this->GetWorld()->GetRealTimeSeconds();
    int lifeTime = ( this->messages.Num() > 1 ) ? 1 : 3;
    if( now - this->m_f_display_time > lifeTime )
    {
        this->messages.RemoveAt( 0 );
        this->m_f_display_time = now;
    }
    if( !this->messages.Num() )
    {
        this->Quit();
        this->m_f_display_time = 0;
    }
}
