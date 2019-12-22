// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Tasks/MultiWarriorTownTask.h"
#include "TownExpenditionTask.generated.h"

/**
 *
 */
UCLASS( )
class FISTWORLD_API UTownExpenditionTask : public UMultiWarriorTownTask
{
    GENERATED_BODY( )

public:
    UTownExpenditionTask( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );
    virtual ~UTownExpenditionTask( ) {}

    bool WarriorSetted( ) override;
    bool Excute( ) override;
    bool SetTargetTown( class UTown* town ) override;
};