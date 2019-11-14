// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/PopupWidget.h"
#include "ShowTownWidget.generated.h"

class UTextBlock;
class UImage;

/**
 * 
 */
UCLASS()
class FISTWORLD_API UShowTownWidget : public UPopupWidget
{
	GENERATED_BODY()
	
public:
    void SetTown( class UTown* town );

    UFUNCTION( BlueprintCallable )
    FString GetTownName();

    UFUNCTION( BlueprintCallable )
    class UTexture2D* GetKingdomLogo();

    UFUNCTION( BlueprintCallable )
    void RegistBaseShowers( UTextBlock* townNameShower, UTextBlock* kingdomNameShower, UImage* kingdomLogoShower );

    UFUNCTION( BlueprintCallable )
    FText GetBusinessDevelopString() const;

    UFUNCTION( BlueprintCallable )
    FText GetAgricultureDevelopString() const;

    UFUNCTION( BlueprintCallable )
    FText GetFoodString() const;

    UFUNCTION( BlueprintCallable )
    FText GetMoneyString() const;

protected:

    class UTown* m_town;

    UTextBlock* m_shower_town_name;
    UTextBlock* m_shower_kingdom_name;
    UImage* m_shower_kingdom_logo;
};
