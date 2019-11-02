// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/PopupWidget.h"
#include "PopupMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UPopupMenuWidget : public UPopupWidget
{
	GENERATED_BODY()
	
protected:
    bool OverrideShowMouseCursor( bool& showMouseCursor ) override;
};
