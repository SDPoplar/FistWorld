// Copyright 2019

#include "TownNamePanelComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Story/Town.h"
#include "Widget/TownNamePanelWidget.h"
#include "Level/TownActor.h"

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

void UTownNamePanelComponent::InitWidget()
{
    UNamePanelComponent::InitWidget();
    ATownActor* ta = Cast<ATownActor>( this->GetOwner() );
    UTown* town = ta ? ta->GetTown() : nullptr;
    UTownNamePanelWidget* widget = town ? Cast<UTownNamePanelWidget>( this->Widget ) : nullptr;
    this->SetVisibility( !!widget );
    if( !widget )
    {
        //  UE_LOG( LogTemp, Error, TEXT( "%s - Failed to load widget when init" ), *( this->GetClass()->GetName() ) );
        return;
    }
    widget->BindTown( town );
}
