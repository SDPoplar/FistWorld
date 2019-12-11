// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "CommonWidgetText.h"
#include "TownTaskNameText.generated.h"

/**
 * 
 */

UCLASS()
class FISTWORLD_API UTownTaskNameText : public UCommonAliFontText
{
    GENERATED_BODY()

public:
    UTownTaskNameText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UAgricultureDevTaskText : public UTownTaskNameText
{
	GENERATED_BODY()
	
public:
    UAgricultureDevTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UBusinessDevTaskText : public UTownTaskNameText
{
    GENERATED_BODY()

public:
    UBusinessDevTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UConscriptTaskText : public UTownTaskNameText
{
    GENERATED_BODY()

public:
    UConscriptTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UExpenditionTaskText : public UTownTaskNameText
{
    GENERATED_BODY()

public:
    UExpenditionTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API ULevyTaskText : public UTownTaskNameText
{
    GENERATED_BODY()

public:
    ULevyTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API USearchTaskText : public UTownTaskNameText
{
    GENERATED_BODY()

public:
    USearchTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API USubsidyTaskText : public UTownTaskNameText
{
    GENERATED_BODY()

public:
    USubsidyTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UTransportTaskText : public UTownTaskNameText
{
    GENERATED_BODY()

public:
    UTransportTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UAssignSoldierTaskText : public UTownTaskNameText
{
    GENERATED_BODY()

public:
    UAssignSoldierTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UInduceCapitulateTaskText : public UTownTaskNameText
{
    GENERATED_BODY()

public:
    UInduceCapitulateTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UExecuteWarriorTaskText : public UTownTaskNameText
{
    GENERATED_BODY()

public:
    UExecuteWarriorTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};
