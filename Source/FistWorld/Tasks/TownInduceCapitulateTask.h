// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Tasks/PrisonTownTask.h"
#include "TownInduceCapitulateTask.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UTownInduceCapitulateTask : public UPrisonTownTask
{
	GENERATED_BODY()

public:
    UTownInduceCapitulateTask( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
    virtual ~UTownInduceCapitulateTask( ) {}

    bool Excute() override;
};
