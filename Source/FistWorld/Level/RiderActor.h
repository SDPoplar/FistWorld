// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Level/FightActor.h"
#include "RiderActor.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API ARiderActor : public AFightActor
{
	GENERATED_BODY()

public:
    ARiderActor();

protected:
    float GetAttackMagnification( EWarriorType targetType, float targetDistance ) const noexcept override;
};
