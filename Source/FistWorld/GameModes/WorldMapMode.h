// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WorldMapMode.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API AWorldMapMode : public AGameModeBase
{
	GENERATED_BODY()

public:
    AWorldMapMode();

    bool FinishRound();

protected:
};
