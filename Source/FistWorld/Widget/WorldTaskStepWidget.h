// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Widget/PopupWidget.h"
#include "WorldTaskStepWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UWorldTaskStepWidget : public UPopupWidget
{
	GENERATED_BODY()

public:
    UFUNCTION( BlueprintCallable )
    void QuitAndCancelTask();
};
