// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Tasks/TownSoldierNumTask.h"
#include "TownAssignSoldierTask.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UTownAssignSoldierTask : public UTownSoldierNumTask
{
	GENERATED_BODY()
public:
    bool SetTargetWarrior( class UWarrior* warrior ) override;
    bool Excute() override;
};
