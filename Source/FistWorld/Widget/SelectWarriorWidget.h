// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/WorldTaskStepWidget.h"
#include "Slate/WarriorListView.h"
#include "SelectWarriorWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API USelectWarriorWidget : public UWorldTaskStepWidget
{
	GENERATED_BODY()
	
public:
    USelectWarriorWidget( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
    void LoadListByTown( int townId, bool playerWarrior = true, bool showBusy = false );

protected:
    UFUNCTION( BlueprintImplementableEvent )
    UWarriorListView* GetWarriorListView();
};
