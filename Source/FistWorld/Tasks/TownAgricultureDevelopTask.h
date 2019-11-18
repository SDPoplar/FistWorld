// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tasks/SingleWarriorTownTask.h"
#include "TownAgricultureDevelopTask.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UTownAgricultureDevelopTask : public USingleWarriorTownTask
{
	GENERATED_BODY()
	
public:
    UTownAgricultureDevelopTask();
    bool SetTargetWarrior( class UWarrior* ) override;
    bool Excute() override;
};
