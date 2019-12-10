// Copyright 2019

#include "TownTaskNameText.h"
#include "Static/Lang/TownTaskName.h"

UAgricultureDevTaskText::UAgricultureDevTaskText( const FObjectInitializer& ObjectInitializer )
    : UCommonAliFontText( ObjectInitializer )
{
    this->InitContent( txtAgricultureDevTaskName, 24 );
}

UBusinessDevTaskText::UBusinessDevTaskText( const FObjectInitializer& ObjectInitializer )
    : UCommonAliFontText( ObjectInitializer )
{
    this->InitContent( txtBusinessDevTaskName, 24 );
}

UConscriptTaskText::UConscriptTaskText( const FObjectInitializer& ObjectInitializer )
    : UCommonAliFontText( ObjectInitializer )
{
    this->InitContent( txtConscriptTaskName, 24 );
}

UExpenditionTaskText::UExpenditionTaskText( const FObjectInitializer& ObjectInitializer )
    : UCommonAliFontText( ObjectInitializer )
{
    this->InitContent( txtExpenditionTaskName, 24 );
}

ULevyTaskText::ULevyTaskText( const FObjectInitializer& ObjectInitializer )
    : UCommonAliFontText( ObjectInitializer )
{
    this->InitContent( txtLevyTaskName, 24 );
}

USearchTaskText::USearchTaskText( const FObjectInitializer& ObjectInitializer )
    : UCommonAliFontText( ObjectInitializer )
{
    this->InitContent( txtSearchTaskName, 24 );
}

USubsidyTaskText::USubsidyTaskText( const FObjectInitializer& ObjectInitializer )
    : UCommonAliFontText( ObjectInitializer )
{
    this->InitContent( txtSubsidyTaskName, 24 );
}

UTransportTaskText::UTransportTaskText( const FObjectInitializer& ObjectInitializer )
    : UCommonAliFontText( ObjectInitializer )
{
    this->InitContent( txtTransportTaskName, 24 );
}

UAssignSoldierTaskText::UAssignSoldierTaskText( const FObjectInitializer& ObjectInitializer )
    : UCommonAliFontText( ObjectInitializer )
{
    this->InitContent( txtAssignSoldierTaskName, 24 );
}
