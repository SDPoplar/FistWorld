// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Tasks/PrisonTownTask.h"
#include "TownExecuteWarriorTask.generated.h"

/**
 *  note that one single warrior can execute multiple prisions at a time
 */
UCLASS()
class FISTWORLD_API UTownExecuteWarriorTask : public UPrisonTownTask
{
	GENERATED_BODY()

public:
    UTownExecuteWarriorTask( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
    virtual ~UTownExecuteWarriorTask() {}

    bool Excute() override;
};
