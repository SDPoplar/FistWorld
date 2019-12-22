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
    UTownTransportTask( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
    virtual bool SetTargetWarrior( class UWarrior* warrior ) override;
    virtual bool SetTransportVolume( int food, int money );
    bool SetTargetTown( UTown* town );
    bool Excute( ) override;
};
