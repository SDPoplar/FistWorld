// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Story/GradableElement.h"
#include "TownNamePanelWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UTownNamePanelWidget : public UUserWidget, public GradableElement
{
	GENERATED_BODY()

public:
    UTownNamePanelWidget( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
    void BindTown( class UTown* town );
	
    EElemGrade GetGrade() const noexcept;

protected:
    UFUNCTION( BlueprintCallable )
    FText GetTownName() const noexcept;

    UFUNCTION( BlueprintCallable )
    bool TownOwnByPlayer() const noexcept;

    UFUNCTION( BlueprintCallable )
    bool TownOwnByKingdom() const noexcept;

    UFUNCTION( BlueprintCallable )
    FLinearColor GetGradeColor() const noexcept override;

    class UTown* m_o_town;
};
