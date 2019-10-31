// Fill out your copyright notice in the Description page of Project Settings.

#include "PopupWidget.h"

/*
UPopupWidget::UPopupWidget( const FObjectInitializer& ObjectInitializer )
{
    UUserWidget( ObjectInitializer );
}
*/

/*
UPopupWidget* UPopupWidget::Popup( UWorld* world )
{
    UPopupWidget *widget = CreateWidgetInstance( world, )
}

*/
void UPopupWidget::Quit()
{
    this->RemoveFromViewport();
}

void UPopupWidget::Popup()
{
    this->AddToViewport( 1000 );
}
