// Fill out your copyright notice in the Description page of Project Settings.

#include "WarriorSelectorItemWidget.h"
#include "Static/Lang/CommonTemplate.h"

#define CHECKWARRIOR( val, def ) this->IsWarriorBinded() ? val : def
#define CHECKWARRIOR_TEXT( val ) CHECKWARRIOR( this->m_warrior->val, FText::GetEmpty() )
#define CHECKWARRIOR_INT( val ) CHECKWARRIOR( this->m_warrior->val, 0 )
#define CHECKWARRIOR_INT2TEXT( val ) CHECKWARRIOR( FText::AsNumber( this->m_warrior->val ), FText::GetEmpty() )

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
    return CHECKWARRIOR( this->m_warrior->GetWarriorType(), EWarriorType::NOTSET );
}

FText UWarriorSelectorItemWidget::GetWarriorName() const noexcept
{
    return this->IsWarriorBinded() ? FText::FromString( this->m_warrior->GetWarriorName() ) : FText::GetEmpty();
}

FText UWarriorSelectorItemWidget::GetWarriorStrong() const noexcept
{
    return CHECKWARRIOR_INT2TEXT( GetStrong() );
}

FText UWarriorSelectorItemWidget::GetWarriorStrongTooltip() const noexcept
{
    return FText::FormatOrdered( txtStrongTooltipTemplate, CHECKWARRIOR_INT( GetStrong() ) );
}

FText UWarriorSelectorItemWidget::GetWarriorIntel() const noexcept
{
    return CHECKWARRIOR_INT2TEXT( GetIntel() );
}

FText UWarriorSelectorItemWidget::GetWarriorIntelTooltip() const noexcept
{
    int val = CHECKWARRIOR_INT( GetIntel() );
    UE_LOG( LogTemp, Display, TEXT( "Get Intel: %d" ), val );
    return FText::FormatOrdered( txtIntelTooltipTemplate, CHECKWARRIOR_INT( GetIntel() ) );
}

FText UWarriorSelectorItemWidget::GetSoldierNum() const noexcept
{
    return CHECKWARRIOR_INT2TEXT( GetSoldierNumber() );
}

FText UWarriorSelectorItemWidget::GetSoldierNumTooltip() const noexcept
{
    return this->GetSoldierNum();
}

FText UWarriorSelectorItemWidget::GetWarriorLevel() const noexcept
{
    return CHECKWARRIOR_INT2TEXT( GetWarriorLevel() );
}

FText UWarriorSelectorItemWidget::GetWarriorLevelTooltip() const noexcept
{
    return this->GetWarriorLevel();
}
