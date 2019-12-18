// Copyright 2019

#include "FightStaticText.h"
#include "Static/Lang/FightInfo.h"

UFightRunAwayText::UFightRunAwayText( const FObjectInitializer& ObjectInitializer )
    : UCommonAliFontText( ObjectInitializer )
{
    this->InitContent( txtRunAway, 24 );
}
