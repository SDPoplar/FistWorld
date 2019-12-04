// Copyright 2019

#include "TownNamePanelComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Story/Town.h"
#include "Widget/TownNamePanelWidget.h"

UTownNamePanelComponent::UTownNamePanelComponent( const FObjectInitializer& ObjectInitializer )
    : UNamePanelComponent( ObjectInitializer )
{
    this->DrawSize = FIntPoint( 160, 40 );
    static ConstructorHelpers::FClassFinder<UTownNamePanelWidget> townnp( TEXT( "/Game/Levels/Res_lv_World/Widget_World_TownNamePanel" ) );
    if( townnp.Succeeded() )
    {
        this->SetWidgetClass( townnp.Class );
    }
    this->bVisibleInRayTracing = false;
}

void UTownNamePanelComponent::BindTown( UTown* town )
{
    this->SetVisibility( !!town );
    UTownNamePanelWidget* widget;
    if( town && ( ( widget = this->GetWidget() ) != nullptr ) )
    {
        widget->BindTown( town );
    }
}

UTownNamePanelWidget* UTownNamePanelComponent::GetWidget() const noexcept
{
    return Cast<UTownNamePanelWidget>( this->Widget );
}
