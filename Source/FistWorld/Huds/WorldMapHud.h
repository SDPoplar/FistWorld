// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Huds/CommonMapHud.h"
#include "WorldMapHud.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API AWorldMapHud : public ACommonMapHud
{
	GENERATED_BODY()
	
public:
    AWorldMapHud();
    void ShowTownInfo( class UTown* town );
    class USingleWarriorSelectWidget* PopupSingleWarriorSelector();
    class UMultiWarriorSelectWidget* PopupMultiWarriorSelector();
    bool PopupTransportVolumeSetter( int maxFood, int maxMoney );
    bool PopupSoldierNumSetter( int max, int current = 0 );

protected:
    void PopupPlayerTownWidget( class UTown* town );

    class UTownTransportVolumeWidget* GetTransportVolumeWidget();
    class UShowTownWidget* GetPlayerTownWidget();

    class USingleWarriorSelectWidget* GetSingleWarriorSelectWidget();
    class UMultiWarriorSelectWidget* GetMultiWarriorSelectWidget();
    class USoldierNumWidget* GetSoldierNumWidget();

    virtual void BeginPlay() override;
    void LoadTopSummaryWidget();

    TSubclassOf<class UKingdomSummaryWidget> topsummaryClass;
    UKingdomSummaryWidget *m_kingdom_summary_widget;

    TSubclassOf<class UShowTownWidget> playertownClass;
    class UShowTownWidget* m_widget_town_player;

    TSubclassOf<class UTownTransportVolumeWidget> transvolumeClass;
    class UTownTransportVolumeWidget* m_widget_transport;

    TSubclassOf<class USingleWarriorSelectWidget> singlewarriorClass;
    class USingleWarriorSelectWidget* m_widget_single_warrior_select;
    TSubclassOf<class UMultiWarriorSelectWidget> multiwarriorClass;
    class UMultiWarriorSelectWidget* m_widget_multi_warrior_select;

    TSubclassOf<class USoldierNumWidget> soldiernumClass;
    class USoldierNumWidget* m_widget_soldier_num;
};
