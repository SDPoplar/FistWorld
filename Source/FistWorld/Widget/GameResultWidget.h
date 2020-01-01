// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Widget/PopupWidget.h"
#include "GameResultWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UGameResultWidget : public UPopupWidget
{
	GENERATED_BODY()
	
public:
    UGameResultWidget( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
    void SetResult( bool playerWin );

protected:
    UFUNCTION( BlueprintCallable )
    bool IsPlayerWin() const noexcept;

    UFUNCTION( BlueprintCallable )
    FText GetResultContent() const noexcept;

    UFUNCTION( BlueprintCallable )
    void PlayerConfirmed();

    bool OverridePauseGame( bool& pause ) override;

    bool m_b_player_win;
};
