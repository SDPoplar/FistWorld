// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/PopupWidget.h"
#include "SingleWarriorSelectWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API USingleWarriorSelectWidget : public UPopupWidget
{
	GENERATED_BODY()
	
public:
    void LoadListByTown( int townId, bool showBusy = false );

    UFUNCTION( BlueprintCallable )
    void QuitAndCancelTask();
};
