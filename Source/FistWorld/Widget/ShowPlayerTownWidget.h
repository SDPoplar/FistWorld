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
};
