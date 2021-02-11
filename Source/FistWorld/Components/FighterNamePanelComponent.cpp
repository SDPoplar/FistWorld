// Copyright 2019

#include "FighterNamePanelComponent.h"
#include "Level/FightActor.h"
#include "Widget/FighterNamePanelWidget.h"
#include "UObject/ConstructorHelpers.h"

UFighterNamePanelComponent::UFighterNamePanelComponent( const FObjectInitializer& ObjectInitializer )
    : UNamePanelComponent( ObjectInitializer )
{
    this->DrawSize = FIntPoint( 100, 40 );
    static ConstructorHelpers::FClassFinder <UFighterNamePanelWidget> fighternp(
        TEXT( "/Game/Levels/Res_lv_Fight/Widget_Fight_FighterNamePanel" ) );
    if( fighternp.Succeeded() )
    {
        this->WidgetClass = fighternp.Class;
    }
}

void UFighterNamePanelComponent::InitWidget()
{
    UNamePanelComponent::InitWidget();
    UFighterNamePanelWidget* widget;
    if( ( widget = Cast<UFighterNamePanelWidget>( this->GetWidget() ) ) == nullptr )
    {
        //  UE_LOG( LogTemp, Error, TEXT( "%s - Failed to load widget" ), *( this->GetClass()->GetName() ) );
        return;
    }
    auto fighter = Cast<AFightActor>( this->GetOwner() );
    if( !fighter )
    {
        //  UE_LOG( LogTemp, Error, TEXT( "%s - Failed to get owner when init widget" ), *( this->GetClass()->GetName() ) );
        return;
    }
    widget->BindFighter( fighter );
}
