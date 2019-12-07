// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Controllers/ModeOverridableController.h"
#include <map>
#include "CommonMapController.generated.h"

UENUM( BlueprintType )
enum class EViewportEdge : uint8
{
    TOP,
    LEFT,
    RIGHT,
    BOTTOM,
};


/**
 * 
 */
UCLASS()
class FISTWORLD_API ACommonMapController : public AModeOverridableController
{
	GENERATED_BODY()

public:
    ACommonMapController( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
    //  virtual ~ACommonMapController();
    void CancelOrCallSysMenu();
    virtual bool CancelCreatingTask();
    bool HasTask() const noexcept;
    bool OverrideTask( class UExcutableTask* task );
    bool IsViewportEdgeLocked( const EViewportEdge side ) const noexcept;
    void MoveTowardsViewportEdge( const EViewportEdge side );
    void SetEdgeLock( EViewportEdge side, bool lock );
    class UExcutableTask* GetTask() const noexcept;
    //  FString GetTaskStepDescribe() const;

protected:
    void BeginPlay() override;
    void SetupInputComponent() override;
    void ReleaseFinishedTask();

    class UExcutableTask* m_o_task;

    std::map<EViewportEdge, bool> m_map_viewport_edge_lock;
};
