// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Slider.h"
#include "IntegerSliderWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UIntegerSliderWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    /*
    UFUNCTION( BlueprintCallable )
    void Init();
    */

    UPROPERTY( EditAnywhere )
    FText sliderTitle;

    UFUNCTION( BlueprintCallable )
    void SetMax( int max );

    int GetValue() const noexcept;

protected:
    UFUNCTION( BlueprintCallable )
    FText GetTitle() const noexcept;

    UFUNCTION( BlueprintCallable )
    FText CurrentValueText() const noexcept;

    UFUNCTION( BlueprintCallable )
    FText MaxValueText() const noexcept;

    UFUNCTION( BlueprintCallable )
    void SetPercent( float percent );

    UFUNCTION( BlueprintImplementableEvent )
    USlider* GetSlider();

    int m_n_max;
    int m_n_current;
};
