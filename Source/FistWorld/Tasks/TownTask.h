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
	UTownTask( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
	virtual ~UTownTask();

    void SetBaseTown( class UTown* town );
    virtual bool SetTargetTown( class UTown* town );
    bool CloseTownWidgetAfterCreate() const noexcept;
    bool Inited() const noexcept;
    int GetTaskCost( ) const noexcept; //Tobe tested!

    void SetTaskCostRate( float nTaskCostRate = 1.0 ) noexcept;  //Tobe tested!
    void PopAlert( const char* sAlerMessage = "You can't do this!" ) const noexcept;//Tobe tested!

protected:
    class AWorldMapHud* GetMapHud() const;

    class UTown* m_o_town;
    class UTown* m_o_target_town;
    class AWorldMapController* m_o_pc;
    bool m_b_hide_townwidget_after_create;
    int m_n_taskCost;
};
