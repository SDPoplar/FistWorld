// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Tasks/SingleWarriorTownTask.h"
#include "TownExecuteTask.generated.h"

/**
 *  note that one single warrior can execute multiple prisions at a time
 */
UCLASS()
class FISTWORLD_API UTownExecuteTask : public USingleWarriorTownTask
{
	GENERATED_BODY()

public:
    UTownExecuteTask( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );
    virtual ~UTownExecuteTask( ) {}

    bool SetTargetWarrior( class UWarrior* );


    bool Excute( ) override;


    void ExecuteWarrior( );
    bool AppendPrision( class UWarrior* );

private:
    TArray<class UWarrior*> m_arr_prisions;
	
};
