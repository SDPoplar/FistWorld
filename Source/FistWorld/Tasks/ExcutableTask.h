// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ExcutableTask.generated.h"

UENUM( BlueprintType )
enum class ETaskStep : uint8
{
    CREATING,
    CHOOSING_TARGET_TOWN,
    CHOOSING_TARGET_WARRIOR,
    CAN_EXCUTE
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

    FString GetLastError() const;

protected:
    ETaskStep m_e_step;

    FString m_s_last_error;
};
