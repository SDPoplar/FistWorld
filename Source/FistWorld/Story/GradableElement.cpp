// Copyright 2019

#include "GradableElement.h"

std::map<EElemGrade, FLinearColor> GradableElement::g_grade_color = {
    std::pair<EElemGrade, FLinearColor>( EElemGrade::NORMAL, FLinearColor( 0, 0, 0, 1 ) ),
    std::pair<EElemGrade, FLinearColor>( EElemGrade::GOOD, FLinearColor( 0.048, 0.463, 0.017 ) ),
    std::pair<EElemGrade, FLinearColor>( EElemGrade::RARE, FLinearColor( 0.156, 0.021, 0.291 ) ),
    std::pair<EElemGrade, FLinearColor>( EElemGrade::LEGEND, FLinearColor( 0.390, 0.179, 0.080 ) )
};

GradableElement::GradableElement()
{}

GradableElement::~GradableElement()
{}

FLinearColor GradableElement::GetColorByGrade( const EElemGrade grade ) noexcept
{
    auto item = g_grade_color.find( grade );
    return ( item == g_grade_color.end() ) ? GradableElement::GetDefaultColor() : item->second;
}

FLinearColor GradableElement::GetDefaultColor() noexcept
{
    return g_grade_color[ EElemGrade::NORMAL ];
}

FLinearColor GradableElement::GetGradeColor() const noexcept
{
    return GradableElement::GetColorByGrade( this->GetGrade() );
}
