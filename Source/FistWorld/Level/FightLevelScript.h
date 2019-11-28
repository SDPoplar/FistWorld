// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "FightLevelScript.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API AFightLevelScript : public ALevelScriptActor
{
	GENERATED_BODY()
	
public:
    UFUNCTION( BlueprintImplementableEvent )
    AActor* GetAttackStartPoint();

    UFUNCTION( BlueprintImplementableEvent )
    AActor* GetDefenceStartPoint();
};
