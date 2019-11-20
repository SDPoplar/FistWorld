// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Widget/PopupWidget.h"
#include "ConfirmBackWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UConfirmBackWidget : public UPopupWidget
{
	GENERATED_BODY()
	
public:
    virtual void ConfirmBack();
};
