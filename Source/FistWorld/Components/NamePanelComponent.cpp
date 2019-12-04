// Copyright 2019

#include "NamePanelComponent.h"

UNamePanelComponent::UNamePanelComponent( const FObjectInitializer& ObjectInitializer )
    : UWidgetComponent( ObjectInitializer )
{
    this->Space = EWidgetSpace::World;
}
