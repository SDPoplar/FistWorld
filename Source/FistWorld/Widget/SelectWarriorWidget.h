// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/PopupWidget.h"
#include "SelectWarriorWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API USelectWarriorWidget : public UPopupWidget
{
	GENERATED_BODY()
	
public:
    void LoadListByTown( int townId, bool showBusy = false );

    UFUNCTION( BlueprintCallable )
    void BindWarriorListView( class UListView* view );

protected:
    class UListView* m_list_view;
};