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

protected:
    void PopupPlayerTownWidget( class UTown* town );
    void PopupHostileTownWidget( class UTown* town );

    class UShowTownWidget* GetPlayerTownWidget();
    class UShowTownWidget* GetHostileTownWidget();

    virtual void BeginPlay() override;
    void LoadTopSummaryWidget();

    TSubclassOf<class UKingdomSummaryWidget> topsummaryClass;
    UKingdomSummaryWidget *m_kingdom_summary_widget;

    TSubclassOf<class UShowTownWidget> playertownClass, hostiletownClass;
    class UShowTownWidget* m_widget_town_player, *m_widget_town_hostile;
};
