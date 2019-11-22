// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ExcutableTask.generated.h"

UENUM( BlueprintType )
enum class ETaskStep : uint8
{
    CREATING,
    CHOOSING_TARGET_TOWN,
    CHOOSING_TARGET_WARRIOR,
    SETTING_TRANSPORT_VOLUME,
    SETTING_SOLDIER_NUMBER,
    FINISHED,
    CANCELED
};

/**
 * 
 */
UCLASS()
class FISTWORLD_API UExcutableTask : public UObject
{
    GENERATED_BODY()

public:
	UExcutableTask( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
	virtual ~UExcutableTask();

    static void LoadDescribes();

    //  bool SetTargetTown( class UTown* town );
    //  bool SetTargetWarrior( class UWarrior* warrior );
    virtual bool Excute();

    virtual FText GetStepDescribe() const;
    ETaskStep GetStep() const noexcept;
    void MarkAsFinished() noexcept;
    void MarkAsCanceled() noexcept;
    bool NeedDisplayStep() const noexcept;
    bool CanCancel() const noexcept;

protected:
    ETaskStep m_e_step;
};
