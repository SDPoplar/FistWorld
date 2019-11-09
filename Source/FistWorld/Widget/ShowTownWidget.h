// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/PopupWidget.h"
#include "ShowTownWidget.generated.h"

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

protected:
    class UTown* m_town;
};
