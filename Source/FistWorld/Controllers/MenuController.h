// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Controllers/FistWorldController.h"
#include "MenuController.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API AMenuController : public AFistWorldController
{
	GENERATED_BODY()

public:
    AMenuController( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );

    virtual void BeginPlay() override;
};
