// Copyright 2019

#include "WorldConfirmBackWidget.h"
#include "Kismet/GameplayStatics.h"

void UWorldConfirmBackWidget::ConfirmBack()
{
    UGameplayStatics::OpenLevel( this, "LV_MainMenu" );
}
