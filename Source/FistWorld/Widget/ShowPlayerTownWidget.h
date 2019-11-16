// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/ShowTownWidget.h"
#include "ShowPlayerTownWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UShowPlayerTownWidget : public UShowTownWidget
{
	GENERATED_BODY()
	
public:
    UFUNCTION( BlueprintCallable )
    bool CreateBusinessDevelopTask();

    UFUNCTION( BlueprintCallable )
    bool CreateAgricultureDevelopTask();

    UFUNCTION( BlueprintCallable )
    bool CreateTownSearchTask();

    UFUNCTION( BlueprintCallable )
    bool CreateTownLevyTask();

    UFUNCTION( BlueprintCallable )
    bool CreateTownSubsidyTask();

    UFUNCTION( BlueprintCallable )
    bool CreateTownConscriptTask();

    bool CreateTownTask( class UTownTask* ( taskMaker )(UObject*) );
};
