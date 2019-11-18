// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Tasks/SingleWarriorTownTask.h"
#include "Story/HasMoneyAndFood.h"
#include "TownTransportTask.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UTownTransportTask : public USingleWarriorTownTask, public HasMoneyAndFood
{
	GENERATED_BODY()
	
public:
    virtual bool SetTargetWarrior( class UWarrior* warrior ) override;
    virtual bool SetTransportVolume( int food, int money );
};
