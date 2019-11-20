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

protected:
    class UTown* m_o_town;
    class UTown* m_o_target_town;
    class AWorldMapController* m_o_pc;
    class AWorldMapHud* m_o_hud;
    bool m_b_hide_townwidget_after_create;
};
