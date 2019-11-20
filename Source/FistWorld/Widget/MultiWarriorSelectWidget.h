// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Widget/SelectWarriorWidget.h"
#include "MultiWarriorSelectWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UMultiWarriorSelectWidget : public USelectWarriorWidget
{
	GENERATED_BODY()
	
public:
    UFUNCTION( BlueprintCallable )
    bool WarriorSelected();
};
