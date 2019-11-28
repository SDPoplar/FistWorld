// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Level/CommonMapViewer.h"
#include "FightMapViewer.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API AFightMapViewer : public ACommonMapViewer
{
	GENERATED_BODY()
	
public:
    AFightMapViewer();

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent( class UInputComponent* PlayerInputComponent ) override;
};
