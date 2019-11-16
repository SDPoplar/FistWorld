// Copyright 2019

#include "MessageBoxWidget.h"

void UMessageBoxWidget::SetDisplayContent( EMessageUseIcon type, FString content )
{
    this->m_e_type = type;
    this->m_s_content = content;
}

FString UMessageBoxWidget::GetContent() const noexcept
{
    return ( this->IsValidLowLevelFast() && this->IsInViewport() ) ? this->m_s_content : FString( "" );
}

EMessageUseIcon UMessageBoxWidget::GetType() const noexcept
{
    return ( this->IsValidLowLevelFast() && this->IsInViewport() ) ? this->m_e_type : EMessageUseIcon::ALERT;
}

void UMessageBoxWidget::CheckLifetime()
{
    //  TODO: quit when lifetime finish
    //  this->Quit();
}
