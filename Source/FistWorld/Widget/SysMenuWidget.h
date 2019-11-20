// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/PopupWidget.h"
#include "SysMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API USysMenuWidget : public UPopupWidget
{
	GENERATED_BODY()
	
public:
    UFUNCTION( BlueprintCallable )
    void ConfirmBack();
};
