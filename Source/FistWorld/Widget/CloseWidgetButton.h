// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
//  #include "Brushes/SlateImageBrush.h"
#include "CloseWidgetButton.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UCloseWidgetButton : public UButton
{
	GENERATED_BODY()
public:
    UCloseWidgetButton();

protected:
    void FillBrush( UTexture2D* texture, FSlateBrush& brush );
};
