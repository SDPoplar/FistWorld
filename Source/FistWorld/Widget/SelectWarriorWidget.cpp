// Fill out your copyright notice in the Description page of Project Settings.

#include "SelectWarriorWidget.h"
#include "ListView.h"
#include "Story/Warrior.h"
#include "Story/Kingdom.h"
#include "FistWorldInstance.h"

USelectWarriorWidget::USelectWarriorWidget( const FObjectInitializer& ObjectInitializer )
    : UWorldTaskStepWidget( ObjectInitializer ), m_list_view( nullptr )
{}

void USelectWarriorWidget::LoadListByTown( int townId, bool playerWarrior, bool showBusy )
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
        if( playerWarrior != UKingdom::OwnByPlayer( warrior->GetBelongKingdom() ) )
        {
            continue;
        }
        if( (warrior->GetStatus() == EWarriorStatus::NORMAL) || ( showBusy && ( warrior->GetStatus() == EWarriorStatus::WORKING ) ) )
        {
            UWarriorIns *ins = NewObject<UWarriorIns>( this );
            *ins = warrior;
            this->m_list_view->AddItem( ins );
        }
    }
}

void USelectWarriorWidget::BindWarriorListView( UListView* view )
{
    this->m_list_view = view;
}
