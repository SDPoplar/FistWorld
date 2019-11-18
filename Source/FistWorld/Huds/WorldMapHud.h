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
    void ShowTownInfo( class ATownActor* town );
    class USingleWarriorSelectWidget* PopupSingleWarriorSelector();
    bool PopupTransportVolumeSetter( int maxFood, int maxMoney );
    bool PopupSoldierNumSetter( int max );
    bool PopupConfirmBackWidget();

protected:
    void PopupPlayerTownWidget( class ATownActor* town );
    void PopupHostileTownWidget( class ATownActor* town );

    class UTownTransportVolumeWidget* GetTransportVolumeWidget();
    class UShowTownWidget* GetPlayerTownWidget();
    class UShowTownWidget* GetHostileTownWidget();

    class USingleWarriorSelectWidget* GetSingleWarriorSelectWidget();
    class USoldierNumWidget* GetSoldierNumWidget();
    class UConfirmBackWidget* GetConfirmBackWidget();

    virtual void BeginPlay() override;
    void LoadTopSummaryWidget();

    TSubclassOf<class UKingdomSummaryWidget> topsummaryClass;
    UKingdomSummaryWidget *m_kingdom_summary_widget;

    TSubclassOf<class UShowTownWidget> playertownClass, hostiletownClass;
    class UShowTownWidget* m_widget_town_player, *m_widget_town_hostile;

    TSubclassOf<class UTownTransportVolumeWidget> transvolumeClass;
    class UTownTransportVolumeWidget* m_widget_transport;

    TSubclassOf<class USingleWarriorSelectWidget> singlewarriorClass;
    class USingleWarriorSelectWidget* m_widget_single_warrior_select;

    TSubclassOf<class USoldierNumWidget> soldiernumClass;
    class USoldierNumWidget* m_widget_soldier_num;

    TSubclassOf<class UConfirmBackWidget> confirmbackClass;
    class UConfirmBackWidget* m_widget_confirm_back;
};
