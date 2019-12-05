// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Widget/PopupWidget.h"
#include "TextBlock.h"
#include "FightResultWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UFightResultWidget : public UPopupWidget
{
	GENERATED_BODY()

public:
    void SetFightResult( bool playerIsAttacker, bool attackerWin,
        TArray<FText> attackerResult, TArray<FText> defencerResult );

protected:
    UFUNCTION( BlueprintImplementableEvent )
    UTextBlock* GetResultTitle();

    UFUNCTION( BlueprintImplementableEvent )
    UTextBlock* GetAttackerResultShower();

    UFUNCTION( BlueprintImplementableEvent )
    UTextBlock* GetDefencerResultShower();

    UFUNCTION( BlueprintCallable )
    void ResultConfirmed();
	
protected:
    bool m_b_attacker_win;
};
