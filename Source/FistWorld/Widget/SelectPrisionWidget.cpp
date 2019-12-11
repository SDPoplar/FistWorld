// Copyright 2019


#include "SelectPrisionWidget.h"
#include "ListView.h"
#include "Story/Warrior.h"
#include "Story/Kingdom.h"
#include "FistWorldInstance.h"

USelectPrisionWidget::USelectPrisionWidget( const FObjectInitializer& ObjectInitializer )
    : UWorldTaskStepWidget( ObjectInitializer )
{}

void USelectPrisionWidget::LoadPrisionList( )
{
    auto list = this->GetPrisionListView( );
    if( !list )
    {
        return;
    }
    list->Clear( );
    auto gi = UFistWorldInstance::GetInstance( this );
    if( !gi )
    {
        return;
    }
    for( UWarrior* warrior : gi->GetWarriorList( ) )
    {
        
        if( ( warrior->GetStatus( ) == EWarriorStatus::PRISON ) )
        {
            UWarriorIns* ins = NewObject<UWarriorIns>( this );
            *ins = warrior;
            list->AddItem( ins );
        }
    }
}

