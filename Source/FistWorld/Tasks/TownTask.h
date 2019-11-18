// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ExcutableTask.h"
#include "TownTask.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UTownTask : public UExcutableTask
{
    GENERATED_BODY()
public:
	UTownTask( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
	virtual ~UTownTask();

    void SetBaseTown( class ATownActor* town );

protected:
    class ATownActor* m_o_actor;
    class UTown* m_o_town;
};
