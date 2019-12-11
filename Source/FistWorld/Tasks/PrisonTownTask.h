// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Tasks/SingleWarriorTownTask.h"
#include "PrisonTownTask.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UPrisonTownTask : public USingleWarriorTownTask
{
	GENERATED_BODY()
	
public:
    UPrisonTownTask( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
    bool SetTargetWarrior( class UWarrior* warrior ) override;

protected:
    class UWarrior* m_o_target_warrior;
};
