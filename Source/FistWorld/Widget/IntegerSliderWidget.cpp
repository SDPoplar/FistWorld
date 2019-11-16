// Copyright 2019

#include "IntegerSliderWidget.h"

void UIntegerSliderWidget::SetMax( int max )
{
    this->m_n_max = max;
    this->m_n_current = 0;
}

int UIntegerSliderWidget::GetValue() const noexcept
{
    return this->m_n_current;
}

FText UIntegerSliderWidget::CurrentValueText() const noexcept
{
    char s[ 12 ];
    sprintf_s( s, 12, "%d", this->m_n_current );
    return FText::FromString( s );
}

FText UIntegerSliderWidget::MaxValueText() const noexcept
{
    char s[ 12 ];
    sprintf_s( s, 12, "%d", this->m_n_max );
    return FText::FromString( s );
}

FText UIntegerSliderWidget::GetTitle() const noexcept
{
    return this->sliderTitle;
}

void UIntegerSliderWidget::SetPercent( float percent )
{
    this->m_n_current = this->m_n_max * percent;
}
