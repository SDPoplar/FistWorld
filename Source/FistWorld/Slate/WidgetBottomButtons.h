// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "WidgetBottomButtons.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UWidgetBottomButtonBase : public UButton
{
	GENERATED_BODY()
	
public:
    UWidgetBottomButtonBase( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};

UCLASS()
class FISTWORLD_API UWidgetBottomConfirmButton : public UWidgetBottomButtonBase
{
    GENERATED_BODY()

public:
    UWidgetBottomConfirmButton( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};
