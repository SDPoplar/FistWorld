// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Controllers/CommonMapController.h"
#include "WorldMapController.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API AWorldMapController : public ACommonMapController
{
	GENERATED_BODY()

public:
    void BeginPlay() override;
    void SetupInputComponent() override;
};
