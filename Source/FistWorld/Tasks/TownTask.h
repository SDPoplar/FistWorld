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
	UTownTask();
	virtual ~UTownTask();

    void SetBaseTown( class UTown* town );
    virtual bool SetTargetWarrior( class UWarrior* warrior );

protected:
    class UTown* m_o_town;
    class UWarrior* m_o_warrior;
};
