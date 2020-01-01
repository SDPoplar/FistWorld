// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FistWorldController.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API AFistWorldController : public APlayerController
{
	GENERATED_BODY()
	
public:
    AFistWorldController( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );

    virtual void BeginPlay() override;

private:
    TSubclassOf<UUserWidget> cursorClass;
};
