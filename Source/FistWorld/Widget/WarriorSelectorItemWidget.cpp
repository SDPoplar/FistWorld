// Fill out your copyright notice in the Description page of Project Settings.

#include "WarriorSelectorItemWidget.h"
#include "Static/Lang/CommonTemplate.h"

#define CHECKWARRIOR( def ) do { if( !this->IsWarriorBinded() ) { return def; } } while( false )
#define CHECKWARRIOR_TEXT CHECKWARRIOR( FText::GetEmpty() )

bool UWarriorSelectorItemWidget::BindWarriorIns( UObject* ins )
{
    auto warrior = Cast<UWarriorIns>( ins );
    if( !warrior )
    {
        return false;
    }
    this->m_warrior = warrior;
    return true;
}

bool UWarriorSelectorItemWidget::IsWarriorBinded( void ) const noexcept
{
    return this->m_warrior && this->m_warrior->IsValidLowLevelFast();
}

EWarriorType UWarriorSelectorItemWidget::GetWarriorType() const noexcept
{
    CHECKWARRIOR( EWarriorType::NOTSET );
    return this->m_warrior->GetWarriorType();
}

FText UWarriorSelectorItemWidget::GetWarriorName() const noexcept
{
    CHECKWARRIOR_TEXT;
    return FText::FromString( this->m_warrior->GetWarriorName() );
}

FText UWarriorSelectorItemWidget::GetWarriorStrong() const noexcept
{
    CHECKWARRIOR_TEXT;
    return FText::AsNumber( this->m_warrior->GetStrong() );
}

FText UWarriorSelectorItemWidget::GetWarriorStrongTooltip() const noexcept
{
    CHECKWARRIOR_TEXT;
    return FText::FormatOrdered<int>( txtStrongTooltipTemplate, this->m_warrior->GetStrong() );
}

FText UWarriorSelectorItemWidget::GetWarriorIntel() const noexcept
{
    CHECKWARRIOR_TEXT;
    return FText::AsNumber( this->m_warrior->GetIntel() );
}

FText UWarriorSelectorItemWidget::GetWarriorIntelTooltip() const noexcept
{
    CHECKWARRIOR_TEXT;
    return FText::FormatOrdered<int>( txtIntelTooltipTemplate, this->m_warrior->GetIntel() );
}

FText UWarriorSelectorItemWidget::GetSoldierNum() const noexcept
{
    CHECKWARRIOR_TEXT;
    return FText::AsNumber( this->m_warrior->GetSoldierNumber() );
}

FText UWarriorSelectorItemWidget::GetSoldierNumTooltip() const noexcept
{
    CHECKWARRIOR_TEXT;
    return FText::FormatOrdered<int>( txtSoldierTooltipTemplate, this->m_warrior->GetSoldierNumber() );
}

FText UWarriorSelectorItemWidget::GetWarriorLevel() const noexcept
{
    CHECKWARRIOR_TEXT;
    return FText::AsNumber( this->m_warrior->GetWarriorLevel() );
}

FText UWarriorSelectorItemWidget::GetWarriorLevelTooltip() const noexcept
{
    CHECKWARRIOR_TEXT;
    return FText::FormatOrdered<FText, int>( txtLevelTooltipTemplate,
        this->m_warrior->GetWarriorTypeString(), this->m_warrior->GetWarriorLevel() );
}
