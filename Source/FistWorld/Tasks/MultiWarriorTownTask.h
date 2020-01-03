// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Tasks/TownTask.h"
#include "MultiWarriorTownTask.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UMultiWarriorTownTask : public UTownTask
{
	GENERATED_BODY()

public:
    int AppendWarrior( class UWarrior* warrior );
    int EachWarrior( bool(warriorProc)( class UWarrior*, void* ), void* res = nullptr );
    virtual bool WarriorSetted();
    virtual bool Excute() override;

protected:
    TArray<class UWarrior*> m_arr_warriors;
};
