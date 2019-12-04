// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "NamePanelComponent.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UNamePanelComponent : public UWidgetComponent
{
	GENERATED_BODY()
	
public:
    UNamePanelComponent( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};
