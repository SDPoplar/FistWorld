// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "CommonWidgetText.h"
#include "TownTaskNameText.generated.h"

/**
 * 
 */

UCLASS()
class FISTWORLD_API UAgricultureDevTaskText : public UCommonAliFontText
{
	GENERATED_BODY()
	
public:
    UAgricultureDevTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UBusinessDevTaskText : public UCommonAliFontText
{
    GENERATED_BODY()

public:
    UBusinessDevTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UConscriptTaskText : public UCommonAliFontText
{
    GENERATED_BODY()

public:
    UConscriptTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UExpenditionTaskText : public UCommonAliFontText
{
    GENERATED_BODY()

public:
    UExpenditionTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API ULevyTaskText : public UCommonAliFontText
{
    GENERATED_BODY()

public:
    ULevyTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API USearchTaskText : public UCommonAliFontText
{
    GENERATED_BODY()

public:
    USearchTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API USubsidyTaskText : public UCommonAliFontText
{
    GENERATED_BODY()

public:
    USubsidyTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UTransportTaskText : public UCommonAliFontText
{
    GENERATED_BODY()

public:
    UTransportTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UAssignSoldierTaskText : public UCommonAliFontText
{
    GENERATED_BODY()

public:
    UAssignSoldierTaskText( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};
