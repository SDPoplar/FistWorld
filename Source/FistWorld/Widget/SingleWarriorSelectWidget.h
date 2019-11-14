// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/SelectWarriorWidget.h"
#include "SingleWarriorSelectWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API USingleWarriorSelectWidget : public USelectWarriorWidget
{
	GENERATED_BODY()
	
public:
    UFUNCTION( BlueprintCallable )
    void QuitAndCancelTask();

    UFUNCTION( BlueprintCallable )
    void WarriorSelected( class UWarriorIns* warrior );
};
