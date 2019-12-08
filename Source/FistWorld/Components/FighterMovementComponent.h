// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "FighterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UFighterMovementComponent : public UFloatingPawnMovement
{
	GENERATED_BODY()
	
public:
    UFighterMovementComponent( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
};
