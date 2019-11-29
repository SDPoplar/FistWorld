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
    //  virtual ~ACommonMapController();
    void CancelOrCallSysMenu();
    virtual bool CancelCreatingTask();
    bool HasTask() const noexcept;
    bool OverrideTask( class UExcutableTask* task );

    class UExcutableTask* GetTask() const noexcept;
    //  FString GetTaskStepDescribe() const;

protected:
    void BeginPlay() override;
    void SetupInputComponent() override;
    void ReleaseFinishedTask();

    class UExcutableTask* m_o_task;
};
