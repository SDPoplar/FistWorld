// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FighterNamePanelWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UFighterNamePanelWidget : public UUserWidget
{
	GENERATED_BODY()

public:
    UFighterNamePanelWidget( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );

    void BindFighter( class AFightActor* fighter ) noexcept;

    UFUNCTION( BlueprintCallable )
    float GetHealthPercent() const noexcept;

    UFUNCTION( BlueprintCallable )
    FText GetFighterName() const noexcept;

protected:
    class AFightActor* m_o_fighter;
};
