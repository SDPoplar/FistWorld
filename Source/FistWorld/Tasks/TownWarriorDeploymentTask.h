// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Tasks/MultiWarriorTownTask.h"
#include "TownWarriorDeploymentTask.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UTownWarriorDeploymentTask : public UMultiWarriorTownTask
{
	GENERATED_BODY()

public:
    UTownWarriorDeploymentTask( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );
    //  virtual ~UTownWarriorDeploymentTask( ) {}

    bool WarriorSetted() override;
    bool Excute() override;
    bool SetTargetTown( class UTown* town ) override;
	
};
