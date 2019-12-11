// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Widget/WorldTaskStepWidget.h"
#include "Slate/WarriorListView.h"
#include "SelectPrisionWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API USelectPrisionWidget : public UWorldTaskStepWidget
{
	GENERATED_BODY()

public:
    USelectPrisionWidget( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );
    void LoadPrisionList( );

protected:
    UFUNCTION( BlueprintImplementableEvent )
        UWarriorListView* GetPrisionListView( );
	
};
