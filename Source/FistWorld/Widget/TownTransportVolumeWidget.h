// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Widget/WorldTaskStepWidget.h"
#include "TownTransportVolumeWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UTownTransportVolumeWidget : public UWorldTaskStepWidget
{
	GENERATED_BODY()
	
public:
    UFUNCTION( BlueprintImplementableEvent )
    void SetMax( int food, int money );

    UFUNCTION( BlueprintCallable )
    bool SetTaskTransportVolume( const class UIntegerSliderWidget* foodSlider, const class UIntegerSliderWidget* money );
};
