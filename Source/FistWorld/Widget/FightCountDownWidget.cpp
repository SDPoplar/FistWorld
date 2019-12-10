// Copyright 2019

#include "FightCountDownWidget.h"
#include "Level/FightReporter.h"

UFightCountDownWidget::UFightCountDownWidget( const FObjectInitializer& ObjectInitializer )
    : UPopupWidget( ObjectInitializer ), m_f_start_at( 0 ), m_o_reporter( nullptr )
{}

void UFightCountDownWidget::SetStart( float startAt, AFightReporter* reporter )
{
    this->m_f_start_at = startAt;
    this->m_o_reporter = reporter;
}

void UFightCountDownWidget::CountDown( float deltaTime )
{
    if( ( this->m_f_start_at <= 0 ) || !this->m_o_reporter )
    {
        return;
    }
    if( this->GetWorld()->GetTimeSeconds() > this->m_f_start_at )
    {
        this->m_o_reporter->TurnOn();
        this->m_f_start_at = 0;
        this->m_o_reporter = nullptr;
        this->Quit();
    }
}

FText UFightCountDownWidget::GetCountDownSeconds() const noexcept
{
    if( (this->m_f_start_at <= 0) || !this->m_o_reporter )
    {
        return FText::FromString( "-" );
    }
    int seconds = (int)(this->m_f_start_at - this->GetWorld()->GetTimeSeconds());
    return FText::AsNumber( seconds );
}
