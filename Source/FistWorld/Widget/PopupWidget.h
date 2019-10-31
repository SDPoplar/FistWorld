// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PopupWidget.generated.h"

/**
 * 
 */
UCLASS()
class FISTWORLD_API UPopupWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    UFUNCTION( BlueprintCallable )
    void Popup();
    //UPopupWidget( const FObjectInitializer& ObjectInitializer );
    //static UPopupWidget* Popup( UWorld* world );
    void Quit();

protected:
    //virtual TSubclassOf<UPopupWidget> GetInstanceClass() = 0;
};
