// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Widget/SysMenuWidget.h"
#include "FightSysMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UFightSysMenuWidget : public USysMenuWidget
{
	GENERATED_BODY()
	
protected:
    bool OverridePauseGame( bool& pauseGame ) override;
};
