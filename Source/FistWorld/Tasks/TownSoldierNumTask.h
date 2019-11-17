// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Tasks/TownTask.h"
#include "Story/HasSoldier.h"
#include "TownSoldierNumTask.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UTownSoldierNumTask : public UTownTask, public HasSoldier
{
	GENERATED_BODY()

public:
    virtual bool SetTargetWarrior( class UWarrior* warrior ) override;
    virtual bool SetTaskSoldierNumber( int num );
};
