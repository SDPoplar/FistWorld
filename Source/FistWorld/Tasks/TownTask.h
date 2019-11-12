// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ExcutableTask.h"

/**
 * 
 */
class FISTWORLD_API UTownTask : public UExcutableTask
{
public:
	UTownTask();
    UTownTask( class UTown* town );
	virtual ~UTownTask();

    virtual void SetTargetWarrior( class UWarrior* warrior );

protected:
    class UTown* m_o_town;
    class UWarrior* m_o_warrior;
};

class FISTWORLD_API UTownBusinessDevelopTask : public UTownTask
{
public:
    UTownBusinessDevelopTask( class UTown* town );
    void SetTargetWarrior( class UWarrior* warrior );
    bool Excute() override;
};
