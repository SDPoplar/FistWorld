// Copyright 2019

#include "ConfirmBackWidget.h"
#include "Kismet/GameplayStatics.h"

void UConfirmBackWidget::ConfirmBack()
{
    UGameplayStatics::OpenLevel( this, "LV_MainMenu" );
}
