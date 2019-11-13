// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Controllers/ModeOverridableController.h"
#include "CommonMapController.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API ACommonMapController : public AModeOverridableController
{
	GENERATED_BODY()

public:
    void CancelOrCallSysMenu();
    virtual bool CancelCreatingTask();
    bool HasTask() const noexcept;
    bool OverrideTask( class UExcutableTask* task );

    FString GetTaskStepDescribe() const;

protected:
    void BeginPlay() override;
    void SetupInputComponent() override;

    class UExcutableTask* m_o_task;
};
