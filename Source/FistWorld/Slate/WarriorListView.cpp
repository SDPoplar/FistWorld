// Copyright 2019

#include "WarriorListView.h"
#include "Widget/WarriorSelectorItemWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "FistWorldInstance.h"

UWarriorListView::UWarriorListView( const FObjectInitializer& ObjectInitializer )
    : UListView( ObjectInitializer )
{
    static ConstructorHelpers::FClassFinder<UWarriorSelectorItemWidget> warriorline(
        TEXT( "/Game/Levels/Res_lv_Common/Widget_Common_WarriorSelectorLine" ) );
    if( warriorline.Succeeded() )
    {
        this->EntryWidgetClass = warriorline.Class;
    }
}

void UWarriorListView::Clear( void )
{
    this->m_arr_sel.Empty();
    this->ClearListItems();
}

TArray<UWarrior*> UWarriorListView::GetSelectedWarriors()
{
    TArray<UWarrior*> sel;
    auto gi = UFistWorldInstance::GetInstance( this );
    if( gi )
    {
        for( int id : this->m_arr_sel )
        {
            UWarrior* warrior = gi->FindWarrior( id );
            if( warrior )
            {
                sel.AddUnique( warrior );
            }
        }
    }
    return sel;
}

bool UWarriorListView::IsWarriorSelected( int warriorId ) const noexcept
{
    return this->m_arr_sel.Find( warriorId ) != INDEX_NONE;
}

bool UWarriorListView::ToggleWarriorSelection( UObject* item )
{
    UWarriorIns* warrior = Cast<UWarriorIns>( item );
    if( !warrior )
    {
        return false;
    }
    int wid = warrior->GetWarriorId();
    if( this->IsWarriorSelected( wid ) )
    {
        this->m_arr_sel.Remove( wid );
        return false;
    }
    else
    {
        switch( this->GetSelectionMode() )
        {
        case ESelectionMode::Multi:
            break;
        case ESelectionMode::None:
            return false;
        default:
            this->m_arr_sel.Empty();
        }
        this->m_arr_sel.AddUnique( wid );
        return true;
    }
}

bool UWarriorListView::HasWarriorSelected() const noexcept
{
    return this->m_arr_sel.Num() > 0;
}
