// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Widget/SysMenuWidget.h"
#include "WorldSysMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UWorldSysMenuWidget : public USysMenuWidget
{
	GENERATED_BODY()

public:
    UFUNCTION( BlueprintCallable )
    bool SaveCurrentGame();

    UFUNCTION( BlueprintCallable )
    bool NextRound();
};
