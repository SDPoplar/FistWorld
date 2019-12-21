// Copyright 2019

#include "ChooseDefenceWarriorWidget.h"
#include "Slate/WarriorListView.h"
#include "Level/Fight.h"
#include "Story/Town.h"
#include "Story/Warrior.h"
#include "FistWorldInstance.h"
#include "GameModes/TownFightMode.h"

#include "Static/Lang/FightInfo.h"

UChooseDefenceWarriorWidget::UChooseDefenceWarriorWidget( const FObjectInitializer& ObjectInitializer )
    : UPopupWidget( ObjectInitializer ), m_o_fight_ins( nullptr )
{}

bool UChooseDefenceWarriorWidget::CanClickOk( void )
{
    auto warriors = this->GetWarriorListView();
    return true
        && this->m_o_fight_ins
        && warriors && warriors->HasWarriorSelected()
        && true;
}

bool UChooseDefenceWarriorWidget::BindFightIns( UFightIns* fight )
{
    auto list = (this->m_o_fight_ins && this->m_o_fight_ins->IsValidLowLevelFast() && this->m_o_fight_ins->IsValid())
        ? this->GetWarriorListView() : nullptr;
    auto gi = list ? UFistWorldInstance::GetInstance( this ) : nullptr;
    if( !gi )
    {
        return false;
    }
    this->m_o_fight_ins = fight;
    int townId = fight->GetTargetTown()->GetTownId();
    for( auto warrior : gi->GetWarriorList() )
    {
        if( ( warrior->GetInTown() != townId ) || !warrior->StatusIn( { EWarriorStatus::NORMAL, EWarriorStatus::WORKING } ) )
        {
            continue;
        }
        UWarriorIns* w = NewObject<UWarriorIns>( this );
        *w = warrior;
        list->AddItem( w );
    }
    return true;
}

void UChooseDefenceWarriorWidget::OnBtnOkClick()
{
    this->m_o_fight_ins->SetDefencer( this->GetWarriorListView()->GetSelectedWarriors() );
    auto gm = ATownFightMode::Get( this );
    gm&& gm->StartFight();
    this->Quit();
}

void UChooseDefenceWarriorWidget::OnBtnRunAwayClick()
{
    auto gm = ATownFightMode::Get( this );
    gm->AttackerWin();
    this->Quit();
}

FText UChooseDefenceWarriorWidget::GetTitleContent() const noexcept
{
    if( !this->m_o_fight_ins )
    {
        return FText::GetEmpty();
    }
    return FText::FormatOrdered<FText, FText>( txtFightDescribe,
        FText::FromString( this->m_o_fight_ins->GetAttackerKingdom()->GetKingdomName() ),
        FText::FromString( this->m_o_fight_ins->GetTargetTown()->GetTownName() ) );
}
