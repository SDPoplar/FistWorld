// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Tasks/TownTransportTask.h"
#include "Story/HasMoneyAndFood.h"
#include "TownLevyTask.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UTownLevyTask : public UTownTransportTask
{
	GENERATED_BODY()
	
public:
    UTownLevyTask( );
    bool SetTargetWarrior( class UWarrior* warrior ) override;
    bool Excute() override;

protected:
};
