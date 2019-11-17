// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/PopupMenuWidget.h"
#include "SysMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API USysMenuWidget : public UPopupMenuWidget
{
	GENERATED_BODY()
	
public:
    UFUNCTION( BlueprintCallable )
    bool SaveCurrentGame();

    UFUNCTION( BlueprintCallable )
    bool NextRound();
};
