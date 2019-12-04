// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/NamePanelComponent.h"
#include "TownNamePanelComponent.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UTownNamePanelComponent : public UNamePanelComponent
{
	GENERATED_BODY()
	
public:
    UTownNamePanelComponent( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );

protected:
    class UTownNamePanelWidget* GetWidget() const noexcept;
    void InitWidget() override;
};
