// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Tasks/TownTransportTask.h"
#include "TownSubsidyTask.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UTownSubsidyTask : public UTownTransportTask
{
	GENERATED_BODY()
	
public:
    UTownSubsidyTask( );
    bool SetTargetWarrior( class UWarrior* warrior ) override;
    bool Excute() override;
};
