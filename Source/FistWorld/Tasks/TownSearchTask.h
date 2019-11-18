// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Tasks/SingleWarriorTownTask.h"
#include "TownSearchTask.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UTownSearchTask : public USingleWarriorTownTask
{
	GENERATED_BODY()

public:
    UTownSearchTask( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
    bool SetTargetWarrior( class UWarrior* ) override;
    bool Excute() override;
};
