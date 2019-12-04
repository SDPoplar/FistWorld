// Copyright 2019

#include "FighterNamePanelWidget.h"
#include "Level/FightActor.h"
#include "Story/Warrior.h"

UFighterNamePanelWidget::UFighterNamePanelWidget( const FObjectInitializer& ObjectInitializer )
    : UUserWidget( ObjectInitializer ), m_o_fighter( nullptr )
{}

void UFighterNamePanelWidget::BindFighter( AFightActor* fighter ) noexcept
{
    this->m_o_fighter = fighter;
}

float UFighterNamePanelWidget::GetHealthPercent() const noexcept
{
    return this->m_o_fighter ? this->m_o_fighter->GetHealthPercent() : 0.0f;
}

FText UFighterNamePanelWidget::GetFighterName() const noexcept
{
    UWarrior* warrior = this->m_o_fighter ? this->m_o_fighter->GetBindedWarrior() : nullptr;
    return warrior ? FText::FromString( warrior->GetWarriorName() ) : FText::GetEmpty();
}
