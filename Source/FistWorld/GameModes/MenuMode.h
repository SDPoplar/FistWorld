// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MenuMode.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API AMenuMode : public AGameModeBase
{
	GENERATED_BODY()
public:
    AMenuMode();

    void StartPlay() override;
};
