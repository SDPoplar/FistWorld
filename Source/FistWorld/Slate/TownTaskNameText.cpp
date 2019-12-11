// Copyright 2019

#include "TownTaskNameText.h"
#include "Static/Lang/TownTaskName.h"

UTownTaskNameText::UTownTaskNameText( const FObjectInitializer& ObjectInitializer )
    : UCommonAliFontText( ObjectInitializer )
{
    this->SetJustification( ETextJustify::Center );
}

UAgricultureDevTaskText::UAgricultureDevTaskText( const FObjectInitializer& ObjectInitializer )
    : UTownTaskNameText( ObjectInitializer )
{
    this->InitContent( txtAgricultureDevTaskName, 24 );
}

UBusinessDevTaskText::UBusinessDevTaskText( const FObjectInitializer& ObjectInitializer )
    : UTownTaskNameText( ObjectInitializer )
{
    this->InitContent( txtBusinessDevTaskName, 24 );
}

UConscriptTaskText::UConscriptTaskText( const FObjectInitializer& ObjectInitializer )
    : UTownTaskNameText( ObjectInitializer )
{
    this->InitContent( txtConscriptTaskName, 24 );
}

UExpenditionTaskText::UExpenditionTaskText( const FObjectInitializer& ObjectInitializer )
    : UTownTaskNameText( ObjectInitializer )
{
    this->InitContent( txtExpenditionTaskName, 24 );
}

ULevyTaskText::ULevyTaskText( const FObjectInitializer& ObjectInitializer )
    : UTownTaskNameText( ObjectInitializer )
{
    this->InitContent( txtLevyTaskName, 24 );
}

USearchTaskText::USearchTaskText( const FObjectInitializer& ObjectInitializer )
    : UTownTaskNameText( ObjectInitializer )
{
    this->InitContent( txtSearchTaskName, 24 );
}

USubsidyTaskText::USubsidyTaskText( const FObjectInitializer& ObjectInitializer )
    : UTownTaskNameText( ObjectInitializer )
{
    this->InitContent( txtSubsidyTaskName, 24 );
}

UTransportTaskText::UTransportTaskText( const FObjectInitializer& ObjectInitializer )
    : UTownTaskNameText( ObjectInitializer )
{
    this->InitContent( txtTransportTaskName, 24 );
}

UAssignSoldierTaskText::UAssignSoldierTaskText( const FObjectInitializer& ObjectInitializer )
    : UTownTaskNameText( ObjectInitializer )
{
    this->InitContent( txtAssignSoldierTaskName, 24 );
}

UInduceCapitulateTaskText::UInduceCapitulateTaskText( const FObjectInitializer& ObjectInitializer )
    : UTownTaskNameText( ObjectInitializer )
{
    this->InitContent( txtInduceCapitulateTaskName, 24 );
}

UExecuteWarriorTaskText::UExecuteWarriorTaskText( const FObjectInitializer& ObjectInitializer )
    : UTownTaskNameText( ObjectInitializer )
{
    this->InitContent( txtExecuteWarriorTaskName, 24 );
}
