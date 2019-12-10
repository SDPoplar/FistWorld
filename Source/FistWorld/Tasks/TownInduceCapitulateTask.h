// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Tasks/SingleWarriorTownTask.h"
#include "TownInduceCapitulateTask.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UTownInduceCapitulateTask : public USingleWarriorTownTask
{
	GENERATED_BODY()

public:
    UTownInduceCapitulateTask( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );
    virtual ~UTownInduceCapitulateTask( ) {}

    bool SetTargetWarrior( class UWarrior* );
    bool SetEnermyWarrior( class UWarrior* );

    bool Excute( ) override;

    int DoWhatToEnermyWarrior( );
    void DemandForSurrender( );

    void ExecuteWarrior( );
    bool BeginInduceCapitulate( );
    void InduceCapitulateSuccess( );
    void InduceCapitulateFaile( );

    

private:
    class UWarrior* m_o_enermy_warrior;
	
};
