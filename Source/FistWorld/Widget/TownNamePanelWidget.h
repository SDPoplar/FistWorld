// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TownNamePanelWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UTownNamePanelWidget : public UUserWidget
{
	GENERATED_BODY()

public:
    UTownNamePanelWidget( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
    void BindTown( class UTown* town );
	
protected:
    UFUNCTION( BlueprintCallable )
    FText GetTownName() const noexcept;

    UFUNCTION( BlueprintCallable )
    bool TownOwnByPlayer() const noexcept;

    UFUNCTION( BlueprintCallable )
    bool TownOwnByKingdom() const noexcept;

    class UTown* m_o_town;
};
