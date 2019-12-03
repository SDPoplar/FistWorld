// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Level/FightActor.h"
#include "ShieldActor.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API AShieldActor : public AFightActor
{
	GENERATED_BODY()
	
public:
    AShieldActor();

protected:
    float GetAttackMagnification( EWarriorType targetType, float targetDistance ) const noexcept override;
};
