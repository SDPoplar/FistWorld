// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ModeOverridableController.generated.h"

enum class EInputMode : int
{
    UIOnly,
    GameOnly,
    GameAndUI
};

/**
 * 
 */
UCLASS()
class FISTWORLD_API AModeOverridableController : public APlayerController
{
	GENERATED_BODY()
public:

    void PushInputMode( const FInputModeGameAndUI& mode );
    void PushInputMode( const FInputModeGameOnly& mode );
    void PushInputMode( const FInputModeUIOnly& mode );
    void PopInputMode();

protected:
    TArray<EInputMode> imhistory;
    TArray<FInputModeGameAndUI> guhis;
    TArray<FInputModeGameOnly> gohis;
    TArray<FInputModeUIOnly> uohis;
};
