// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Controllers/ModeOverridableController.h"
#include "CommonMapController.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API ACommonMapController : public AModeOverridableController
{
	GENERATED_BODY()

public:
    void CancelOrCallSysMenu();

protected:
    void BeginPlay() override;
    void SetupInputComponent() override;
};
