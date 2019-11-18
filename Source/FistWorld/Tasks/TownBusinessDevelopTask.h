// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tasks/SingleWarriorTownTask.h"
#include "TownBusinessDevelopTask.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UTownBusinessDevelopTask : public USingleWarriorTownTask
{
	GENERATED_BODY()
public:
    UTownBusinessDevelopTask();
    bool SetTargetWarrior( class UWarrior* warrior ) override;
    bool Excute() override;
};
