// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/Image.h"
#include "PopupWidgetBackground.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UPopBgBase : public UImage
{
    GENERATED_BODY()

public:
    UPopBgBase( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UPopBgTitle : public UPopBgBase
{
    GENERATED_BODY()

public:
    UPopBgTitle( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UPopBgCenterTitle : public UPopBgBase
{
    GENERATED_BODY()

public:
    UPopBgCenterTitle( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UPopBgTitleWithExit : public UPopBgBase
{
	GENERATED_BODY()
	
public:
    UPopBgTitleWithExit( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UPopBgBodyRV : public UPopBgBase
{
    GENERATED_BODY()

public:
    UPopBgBodyRV( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UPopBgBottom : public UPopBgBase
{
    GENERATED_BODY()

public:
    UPopBgBottom( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UPopBgBottomAllLineButton : public UPopBgBase
{
    GENERATED_BODY()

public:
    UPopBgBottomAllLineButton( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UPopBgBottomSingleButton : public UPopBgBase
{
    GENERATED_BODY()

public:
    UPopBgBottomSingleButton( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UPopBgBottomDoubleButton : public UPopBgBase
{
    GENERATED_BODY()

public:
    UPopBgBottomDoubleButton( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UPopBgBottomCenterSingleButton : public UPopBgBase
{
    GENERATED_BODY()

public:
    UPopBgBottomCenterSingleButton( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};
