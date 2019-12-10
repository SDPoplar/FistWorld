// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Widget/PopupWidget.h"
#include "FightCountDownWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UFightCountDownWidget : public UPopupWidget
{
	GENERATED_BODY()
	
public:
    UFightCountDownWidget( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
    void SetStart( float startAt, class AFightReporter* reporter );

protected:
    UFUNCTION( BlueprintCallable )
    void CountDown( float deltaTime );

    UFUNCTION( BlueprintCallable )
    FText GetCountDownSeconds() const noexcept;

    float m_f_start_at;
    class AFightReporter* m_o_reporter;
};
