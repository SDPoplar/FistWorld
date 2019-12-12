// Copyright 2019

#include "IntegerSliderWidget.h"

void UIntegerSliderWidget::Init( int max, int current )
{
    this->m_n_current = current;
    this->m_n_max = max;
    USlider* slider = this->GetSlider();
    if( slider )
    {
        slider->SetValue( 1.0 * current / max );
    }
}

void UIntegerSliderWidget::SetMax( int max )
{
    this->Init( max );
}

int UIntegerSliderWidget::GetValue() const noexcept
{
    return this->m_n_current;
}

FText UIntegerSliderWidget::CurrentValueText() const noexcept
{
    return FText::AsNumber( this->m_n_current );
}

FText UIntegerSliderWidget::MaxValueText() const noexcept
{
    return FText::AsNumber( this->m_n_max );
}

FText UIntegerSliderWidget::GetTitle() const noexcept
{
    return this->sliderTitle;
}

void UIntegerSliderWidget::SetPercent( float percent )
{
    this->m_n_current = this->m_n_max * percent;
}
