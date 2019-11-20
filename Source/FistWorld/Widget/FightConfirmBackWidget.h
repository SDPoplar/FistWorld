// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Widget/ConfirmBackWidget.h"
#include "FightConfirmBackWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UFightConfirmBackWidget : public UConfirmBackWidget
{
	GENERATED_BODY()
	
public:
    UFUNCTION( BlueprintCallable )
    void ConfirmBack() override;
};
