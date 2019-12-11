// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Tasks/TownTask.h"
#include "SingleWarriorTownTask.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API USingleWarriorTownTask : public UTownTask
{
	GENERATED_BODY()
	
public:
    USingleWarriorTownTask( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );

    virtual bool SetTargetWarrior( class UWarrior* warrior );
    virtual bool Excute() override;

protected:
    class UWarrior* m_o_warrior;
};
