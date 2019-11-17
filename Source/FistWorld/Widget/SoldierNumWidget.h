// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Widget/WorldTaskStepWidget.h"
#include "SoldierNumWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API USoldierNumWidget : public UWorldTaskStepWidget
{
	GENERATED_BODY()
public:
    UFUNCTION( BlueprintImplementableEvent )
    void SetMax( int max );

    UFUNCTION( BlueprintCallable )
    bool SetTaskSoldierNum( const class UIntegerSliderWidget* slider );
};
