// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Widget/ConfirmBackWidget.h"
#include "WorldConfirmBackWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UWorldConfirmBackWidget : public UConfirmBackWidget
{
	GENERATED_BODY()

public:
    UFUNCTION( BlueprintCallable )
    void ConfirmBack() override;

};
