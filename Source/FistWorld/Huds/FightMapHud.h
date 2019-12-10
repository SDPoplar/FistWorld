// Copyright 2019

#pragma once

#include "CoreMinimal.h"
#include "Huds/CommonMapHud.h"
#include "FightMapHud.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API AFightMapHud : public ACommonMapHud
{
	GENERATED_BODY()
	
public:
    AFightMapHud( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );
    class UFightResultWidget* GetFightResultWidget();

    bool PopPlayerDefencerChooser( int townId );
    bool PopFightCountDown( int seconds, class AFightReporter* reporter );

protected:
    class UPlayerChooseDefenceWarriorWidget* GetPlayerDefencerChooser();
    class UFightCountDownWidget* GetFightCountDownWidget();

    TSubclassOf<class UFightResultWidget> fightresultClass;
    class UFightResultWidget* m_widget_result;

    TSubclassOf<class UPlayerChooseDefenceWarriorWidget> defencerClass;
    class UPlayerChooseDefenceWarriorWidget* m_widget_player_defencer_chooser;

    TSubclassOf<class UFightCountDownWidget> countdownClass;
    class UFightCountDownWidget* m_widget_fight_count_down;
};
