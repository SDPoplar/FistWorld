// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WorldMapHud.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API AWorldMapHud : public AHUD
{
	GENERATED_BODY()
	
public:
    AWorldMapHud();

protected:
    virtual void BeginPlay() override;
    void LoadTopSummaryWidget();

    TSubclassOf<class UKingdomSummaryWidget> topsummaryClass;
    UKingdomSummaryWidget *m_kingdom_summary_widget;
};
