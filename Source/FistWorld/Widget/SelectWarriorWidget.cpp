// Fill out your copyright notice in the Description page of Project Settings.

#include "SelectWarriorWidget.h"
#include "ListView.h"
#include "Story/Warrior.h"
#include "FistWorldInstance.h"

void USelectWarriorWidget::LoadListByTown( int townId, bool showBusy )
{
    if( !this->m_list_view || !this->m_list_view->IsValidLowLevelFast() )
    {
        return;
    }
    this->m_list_view->ClearListItems();
    auto gi = UFistWorldInstance::GetInstance( this );
    if( !gi )
    {
        return;
    }
    for( UWarrior* warrior : gi->GetWarriorList() )
    {
        if( warrior->GetInTown() != townId )
        {
            continue;
        }
        if( (warrior->GetStatus() == EWarriorStatus::NORMAL) || ( showBusy && ( warrior->GetStatus() == EWarriorStatus::WORKING ) ) )
        {
            UWarriorIns *ins = NewObject<UWarriorIns>();
            *ins = warrior;
            this->m_list_view->AddItem( ins );
        }
    }
}

void USelectWarriorWidget::BindWarriorListView( UListView* view )
{
    this->m_list_view = view;
}
