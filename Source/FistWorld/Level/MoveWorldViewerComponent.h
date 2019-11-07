// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "MoveWorldViewerComponent.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UMoveWorldViewerComponent : public UFloatingPawnMovement
{
	GENERATED_BODY()
	
public:
    UFUNCTION( BlueprintCallable )
    void StartMove( FVector target, int steps );

    /*
    UFUNCTION( BlueprintCallable )
    void DirectMove( FVector target );
    */

    void MoveTick();

protected:
    TArray<TArray<FVector>> m_movement_tasks;
};
