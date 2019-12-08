// Copyright 2019

#include "FightSysMenuWidget.h"

bool UFightSysMenuWidget::OverridePauseGame( bool& pauseGame )
{
    UE_LOG( LogTemp, Display, TEXT( "Override game pause" ) );
    pauseGame = true;
    return true;
}
