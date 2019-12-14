// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Tasks/TownSoldierNumTask.h"
#include "TownConscriptTask.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UTownConscriptTask : public UTownSoldierNumTask
{
	GENERATED_BODY()
public:
    UTownConscriptTask( );
    bool SetTargetWarrior( class UWarrior* warrior ) override;
    bool Excute() override;
};
