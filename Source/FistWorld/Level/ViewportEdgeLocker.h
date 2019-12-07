// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Controllers/CommonMapController.h"
#include "ViewportEdgeLocker.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API AViewportEdgeLocker : public ATriggerBox
{
	GENERATED_BODY()
	
public:
    AViewportEdgeLocker( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );

    UPROPERTY( EditAnywhere )
    EViewportEdge bindEdge;

protected:
    UFUNCTION()
    void ActorIn( AActor* self, AActor* otherActor );

    UFUNCTION()
    void ActorOut( AActor* self, AActor* otherActor );
};
