// Copyright 2019

#include "WidgetBottomButtons.h"
//  #include "CommonWidgetText.h"

UWidgetBottomButtonBase::UWidgetBottomButtonBase( const FObjectInitializer& ObjectInitializer )
    : UButton( ObjectInitializer )
{}

UWidgetBottomConfirmButton::UWidgetBottomConfirmButton( const FObjectInitializer& ObjectInitializer )
    : UWidgetBottomButtonBase( ObjectInitializer )
{
    /*
    auto innertext = CreateDefaultSubobject<UCommonConfirmText>( "inner text" );
    this->AddChild( innertext );
    */
}
