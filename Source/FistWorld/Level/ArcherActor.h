// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Level/FightActor.h"
#include "ArcherActor.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API AArcherActor : public AFightActor
{
	GENERATED_BODY()
	
public:
    AArcherActor();

protected:
    float GetAttackMagnification( EWarriorType targetType, float targetDistance ) const noexcept override;
};
