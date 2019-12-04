// Copyright 2019

#include "TownNamePanelWidget.h"
#include "Story/Town.h"

UTownNamePanelWidget::UTownNamePanelWidget( const FObjectInitializer& ObjectInitializer )
    : UUserWidget( ObjectInitializer ), m_o_town( nullptr )
{}

void UTownNamePanelWidget::BindTown( UTown* town )
{
    this->m_o_town = town;
}

FText UTownNamePanelWidget::GetTownName() const noexcept
{
    return this->m_o_town ? FText::FromString( this->m_o_town->GetTownName() ) : FText::GetEmpty();
}

bool UTownNamePanelWidget::TownOwnByKingdom() const noexcept
{
    return this->m_o_town && this->m_o_town->OwnByKingdom();
}

bool UTownNamePanelWidget::TownOwnByPlayer() const noexcept
{
    return this->m_o_town && this->m_o_town->OwnByPlayer();
}

EElemGrade UTownNamePanelWidget::GetGrade() const noexcept
{
    return this->m_o_town ? this->m_o_town->GetGrade() : EElemGrade::NORMAL;
}

FLinearColor UTownNamePanelWidget::GetGradeColor() const noexcept
{
    EElemGrade grade = this->GetGrade();
    return (grade == EElemGrade::NORMAL) ? FLinearColor( 255, 255, 255, 1 ) : GradableElement::GetGradeColor();
}
