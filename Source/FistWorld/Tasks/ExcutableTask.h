// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ExcutableTask.generated.h"

UENUM( BlueprintType )
enum class ETaskStep : uint8
{
    CREATING,
    CHOOSING_TARGET_TOWN,
    CHOOSING_TARGET_WARRIOR
};

/**
 * 
 */
class FISTWORLD_API UExcutableTask
{
public:
	UExcutableTask();
	virtual ~UExcutableTask();

    //  bool SetTargetTown( class UTown* town );
    //  bool SetTargetWarrior( class UWarrior* warrior );
    virtual bool Excute();

    virtual FString GetStepDescribe() const;
    FString GetLastError() const;
    ETaskStep GetStep() const noexcept;

protected:
    ETaskStep m_e_step;

    FString m_s_last_error;
};