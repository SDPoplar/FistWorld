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
    void ResetBothBirthPoint();
    FVector GetAttackerNextBirthPoint() noexcept;
    FVector GetDefencerNextBirthPoint() noexcept;

    FVector GetAttackerStartPointLocation() const noexcept;
    FVector GetDefencerStartPointLocation() const noexcept;

    UFUNCTION( BlueprintImplementableEvent )
    AActor* GetAttackStartPoint() const;

    UFUNCTION( BlueprintImplementableEvent )
    AActor* GetDefenceStartPoint() const;

protected:

    FVector GetBirthPoint( FVector basepoint, int index ) const noexcept;

    int m_n_bp_index_attacker;
    int m_n_bp_index_defencer;

};
