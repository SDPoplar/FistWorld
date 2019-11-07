// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WorldMapController.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API AWorldMapController : public APlayerController
{
	GENERATED_BODY()

public:
    void BeginPlay() override;
};
