// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "KingdomSummaryWidget.generated.h"

class UKingdom;

/**
 * 
 */
UCLASS()
class FISTWORLD_API UKingdomSummaryWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    static UKingdomSummaryWidget* Create( TSubclassOf<UKingdomSummaryWidget> clsName, UWorld* world, FName widgetName );
    UKingdom* BindKingdom( UKingdom* kingdom );

    UFUNCTION( BlueprintCallable )
    UTexture2D* GetKingdomLogo() const noexcept;

    UFUNCTION( BlueprintCallable )
    FString GetKingdomName() const noexcept;

    UFUNCTION( BlueprintCallable )
    ESlateVisibility PlayerHasTask() const;

    UFUNCTION( BlueprintCallable )
    void BindTaskShower( class UTextBlock* taskShower );

    UFUNCTION( BlueprintCallable )
    FText GetPlayerTownNum() const noexcept;

    UFUNCTION( BlueprintCallable )
    FText GetPlayerWarriorNum() const noexcept;

    UFUNCTION( BlueprintCallable )
    FText GetPlayerKingdomFood() const noexcept;

    UFUNCTION( BlueprintCallable )
    FText GetPlayerKingdomMoney() const noexcept;

protected:
    UKingdom* m_o_kingdom;

    class UTextBlock* m_o_task_shower;
};
