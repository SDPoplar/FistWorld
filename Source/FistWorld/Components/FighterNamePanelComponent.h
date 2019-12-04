// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/NamePanelComponent.h"
#include "FighterNamePanelComponent.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UFighterNamePanelComponent : public UNamePanelComponent
{
	GENERATED_BODY()
	
public:
    UFighterNamePanelComponent( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );

protected:
    void InitWidget() override;
};
