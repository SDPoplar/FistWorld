// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Widget/PopupWidget.h"
#include "ChooseDefenceWarriorWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UChooseDefenceWarriorWidget : public UPopupWidget
{
	GENERATED_BODY()
	
public:
    UChooseDefenceWarriorWidget( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
    bool BindFightIns( class UFightIns* fight );

    UFUNCTION( BlueprintCallable )
    bool CanClickOk();

    UFUNCTION( BlueprintCallable )
    void OnBtnRunAwayClick();

    UFUNCTION( BlueprintCallable )
    void OnBtnOkClick();

    UFUNCTION( BlueprintCallable )
    FText GetTitleContent() const noexcept;

    UFUNCTION( BlueprintImplementableEvent )
    class UWarriorListView* GetWarriorListView();

protected:
    class UFightIns* m_o_fight_ins;
};
